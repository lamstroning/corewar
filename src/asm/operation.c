/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:49:31 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/04 18:49:33 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		pars_lbl(char *line, t_lbl *lbl)
{
	int		end_mark;

	end_mark = ft_strchr(line, LABEL_CHAR) - line;
	lbl->name = ft_strsub(line, 0, end_mark);
	lbl->cmd = save_lbl_cmd(&line[end_mark + 1]);
	lbl->next = (t_lbl *)ft_memalloc(sizeof(t_lbl));
	return (0);
}

char	*save_lbl_cmd(char *line)
{
	int		i;
	char	*tmp;

	tmp = ft_strtrim(line);
	i = 0;
	while (1)
	{
		if (tmp[i] == '\0')
		{
			free(tmp);
			i = 0;
			if (get_next_line(g_fd_read, &line) <= 0)
				valid_error(1);
			tmp = ft_strtrim(line);
			free(line);
		}
		if (ft_isspace(tmp[i]) == 0)
			break ;
		++i;
	}
	output_oper(tmp);
	return (ft_strdup(&tmp[i]));
}

int		check_lbl(char *line, t_lbl *lbl)
{
	int		i;

	i = 0;
	if (ft_strchr(line, LABEL_CHAR) == NULL)
		return (output_oper(line));
	while (line[i] != '\0')
	{
		if (line[i++] == LABEL_CHAR)
			break ;
	}
	if (i > 0 && line[i - 2] == DIRECT_CHAR)
		return (output_oper(line));
	return (pars_lbl(line, lbl));
}

int		output_oper(char *line)
{
	int		i;
	char	**oper;

	oper = ft_strsplit(line, ' ');
	i = -1;
	while (++i < REG_NUMBER)
	{
		if (ft_strcmp(oper[0], g_op_tab[i].name) == 0)
		{
				if (i < 10)
					ft_putchar_fd((char)0, g_fd_new);
				ft_putchar_fd((char)i + 1, g_fd_new);
				pars_arg(line, i);
				break ;
				// res[0] = i + 1;
		}
	}
	return (0);
}

int		pars_arg(char *line, int index)
{
	int		i;
	char	*name;

	i = 0;
	name = ft_strsub(line, i, ft_strchr(line, ' ') - line);
	while (ft_isspace(line[i]) == 0)
		i++;
	ft_rewrite(&line, ft_strsub(line, i + 1, ft_strlen(line) - i));
	// read_name(name);
	read_arg(line, index);
	return (1);
}
