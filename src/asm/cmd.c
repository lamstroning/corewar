/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:55:18 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/18 18:55:20 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_cmd		*create_cmd(t_type *file, t_header *head)
{
	int		i;
	t_cmd	*cmd;

	cmd = new_cmd(NULL);
	i = -1;
	while (++i <= file[0].count)
	{
		if (file[i].type == LABEL || file[i].type == INS)
		{
			cmd->lbl = file[i].type == LABEL ? file[i].str : NULL;
			i += save_cmd(cmd, &file[i]);
			cmd->next = new_cmd(cmd);
			cmd = cmd->next;
		}
	}
	del_cmd(cmd, 2);
	head->prog_size = roll_back(&cmd);
	return (cmd);
}

int		save_cmd(t_cmd *cmd, t_type *file)
{
	int		i;
	int		reg;
	int		count;

	i = 0;
	count = 0;
	while (file[i].type != INS)
		i++;
	reg = output_oper(file[i].str);
	if (g_op_tab[reg].nb_arg > 1)
		cmd->size += 1;
	while (file[i].type == NL)
		++i;
	//this while searching NL, but NL Not found
	//REMOVE COUNT, IT'S BAD!!!!!!!! FIX ME PLS!!!!!!
	while (file[i].type != NL && count <= 1)
	{
		if (file[i].type == INS)
			count++;
		if (count == 2)
			return (i - 1);
		if (file[i].type == INS)
			cmd->size += 1;
		else if (file[i].type == REG)
			cmd->size += 1;
		else if (file[i].type == DIR)
			cmd->size += g_op_tab[reg].label == 0 ? 4 : 2;
		else if (file[i].type == INDIR)
			cmd->size += 8;
		i++;
	}
	return (i);
}

t_cmd		*new_cmd(t_cmd *last)
{
	t_cmd	*cmd;

	cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	cmd->prev = last;
	cmd->id = last == NULL ? 0 : last->id + 1;
	//delete
	if (cmd->id == 67)
		write(1, "\0", 1);
	//delete
	cmd->lbl = NULL;
	cmd->size = 0;
	return (cmd);
}

void		del_cmd(t_cmd *cmd, int count)
{
	while (count > 0 && cmd->prev != NULL)
	{
		free(cmd->next);
		cmd->next = NULL;
		cmd = cmd->prev;
		count--;
	}
}

int			roll_back(t_cmd **cmd)
{
	int		size;

	size = 0;
	while ((*cmd)->prev != NULL)
	{
		size += (*cmd)->size;
		*cmd = (*cmd)->prev;
	}
	size += (*cmd)->size;
	return (size);
}
