/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:08:46 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/16 20:13:38 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_type	*read_file(char *name)
{
	char	*line;
	char	**list;
	int		fd;

	list = NULL;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(list = addlist(list, line)))
		{
			dellist(list);
			free(line);
			return (NULL);
		}
		free(line);
	}
	return (settype(list));
}

void	check_file(t_header *head, t_type *file, t_cmd *cmd)
{
	int		i;

	i = -1;
	while (++i != file[0].count)
	{
		if (file[i].type == NL)
			continue ;
		else if (file[i].type == LABEL || file[i].type == INS)
		{
			//delete
/*Trash*/			if (i == 172)
/*Trash*/			write(1 , "\0", 1);
			//delete
			i += pars_lbl(&file[file[i].type == LABEL ? i + 1 : i], cmd);
			cmd = cmd == NULL ? NULL : cmd->next;
		}
		else if (file[i].type == CMD)
			check_line(head, &file[i]);
	}
}

int		check_line(t_header *head, t_type *file)
{
	u_byte	size;

	if (ft_strstr(file->str, NAME_CMD_STRING) != NULL)
	{
		pars_line(head->prog_name, PROG_NAME_LENGTH, file);
		size.ints = head->prog_size;
		size.ints = reverse(size.ints, 4);
		make_bin((char *)size.chars, 4, 0);
	}
	else if (ft_strstr(file->str, COMMENT_CMD_STRING) != NULL)
		pars_line(head->comment, COMMENT_LENGTH, file);
	return (1);
}

void		pars_line(char *line, int size, t_type *file)
{
	int		i;
	char	*tmp;

	i = -1;
	while (file->type != STR)
		++file;
	tmp = file->str;
	if (ft_strlen(tmp) > (size_t)size)
		valid_error(2);
	while (tmp[++i] != '\0')
		line[i] = tmp[i];
	while (++i < size)
		line[i] = '\0';
	free(tmp);
	make_bin(line, size, 4);
}
