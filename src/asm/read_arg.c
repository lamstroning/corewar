/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:10:13 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/07 20:10:14 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char		arg_sum(char byte, int type)
{
	byte = byte | type;
	byte = byte << 2;
	return (byte);
}

int		write_arg(t_type *file, int tdir, t_cmd *cmd)
{
	int		i;
	u_byte	args;
	int		size;

	i = -1;
	while (file[++i].type != NL)
	{
		if (file[i].type == INS)
			continue ;
		args.ints = 0;
		size = -1;
		if (file[i].type == DIR)
		{
			if (ft_isdigit(file[i].str[0]) == 0)
				args.ints = search_lbl_next(file[i].str, cmd);
			else
				args.ints = ft_atoi(&file[i].str[0]);
			args.ints = reverse(args.ints, tdir);
			size = tdir;
		}
		else if (file[i].type == REG)
		{
			args.chars[0] = ft_atoi(&file[i].str[1]);;
			size = 1;
		}
		else if (file[i].type == INDIR)
			args.chars[3] = ft_atoi(file[i].str);
		if (size != -1)
			make_bin((char *)args.chars, size, 0);
	}
	return (i);
}

int		search_lbl_prev(char *str, t_cmd *cmd)
{
	t_cmd	*tmp;
	int		size;

	size = 0;
	tmp = cmd;
	while (tmp->prev != NULL)
	{
		if (tmp->lbl != NULL && ft_strstr(str, tmp->lbl) != NULL)
			return (size);
		tmp = tmp->prev;
		size -= tmp->size;
	}
	// if (size == 0)
	// 	return (search_lbl_next(str, cmd));
	return (size);
}

int		search_lbl_next(char *str, t_cmd *cmd)
{
	t_cmd	*tmp;
	int		size;

	size = 0;
	tmp = cmd;
	while (tmp->next != NULL)
	{
		if (tmp->lbl != NULL && ft_strstr(str, tmp->lbl) != NULL)
			return (size);
		size += tmp->size;
		tmp = tmp->next;
	}
	if (size == 0)
		return (search_lbl_prev(str, cmd));
	return (size);
}

unsigned int reverse(unsigned int x, int cnt)
{
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	if (cnt == 4)
		x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	return (x);
}
