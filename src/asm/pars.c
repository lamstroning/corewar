/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:08:46 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/04 12:08:48 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	read_file(t_header *head, int fd, char *name)
{
	int		fd_as;
	char	*line;

	fd_as = open(name, O_RDONLY);
	while (get_next_line(fd_as, &line) > 0)
	{
		check_line(head, line, fd);
		free(line);
	}
}

int		check_line(t_header *head, char *line, int fd)
{
	int		check;

	check = 1;
	if (ft_strstr(line, NAME_CMD_STRING) != NULL)
		check = pars_name(head, line, fd);
	if (ft_strstr(line, COMMENT_CMD_STRING) != NULL)
		check = pars_comment(head, line, fd);
	if (check == 0)
		valid_error(2);
	return (1);
}

int		pars_name(t_header *head, char *name, int fd)
{
	int		i;
	int		full;
	char	*tmp;

	i = -1;
	full = 0;
	tmp = ft_strchr(name, '"');
	if (tmp == NULL)
		return (0);
	tmp = ft_strsub(tmp, 1, ft_strrchr(name, '"') - name - 1);
	if (ft_strlen(tmp) > PROG_NAME_LENGTH)
		valid_error(2);
	while (tmp[++i + 1] != '\0')
		head->prog_name[i] = tmp[i];
	while (++i < PROG_NAME_LENGTH)
		head->prog_name[i] = '\0';
	free(tmp);
	make_bin(head->prog_name, fd, PROG_NAME_LENGTH);
	return (1);
}

int		pars_comment(t_header *head, char *name, int fd)
{
	int		i;
	int		full;
	char	*tmp;

	i = -1;
	full = 0;
	tmp = ft_strchr(name, '"');
	if (tmp == NULL)
		return (0);
	tmp = ft_strsub(tmp, 1, ft_strrchr(name, '"') - name);
	if (ft_strlen(tmp) > COMMENT_LENGTH)
		valid_error(2);
	while (tmp[++i + 1] != '\0')
		head->comment[i] = tmp[i];
	while (++i < COMMENT_LENGTH)
		head->comment[i] = '\0';
	free(tmp);
	make_bin(head->comment, fd, COMMENT_LENGTH);
	return (1);
}
