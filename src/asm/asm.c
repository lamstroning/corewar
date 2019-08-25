/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:19:40 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/12 17:51:20 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			g_fd_new = -1;
int			g_fd_read = -1;

int		main(int argc, char **argv)
{
	t_type		*file;
	t_header	*head;
	t_cmd		*cmd;

	file = read_file(argv[1]);
	if (argc != 2)
		valid_error(1);
	head = (t_header*)ft_memalloc(sizeof(t_header));
	g_fd_new = init_file(argv[1]);
	head->magic = COREWAR_EXEC_MAGIC;
	print_magic();
	cmd = create_cmd(file, head);
	// g_fd_read = open(argv[1], O_RDONLY);
	check_file(head, file, cmd);
	// dellist(file);
	free(head);
	close(g_fd_read);
	close(g_fd_new);
	return (0);
}

int		init_file(char *name)
{
	int		fd;
	char	*type;
	char	*fname;
	char	*nametype;

	type = ft_strchr(name, '.');
	if (type == NULL || ft_strchr(type, 's') == NULL || ft_strlen(type) != 2)
		valid_error(1);
	type = "cor";
	fname = ft_strsub(name, 0, ft_strlen(name) - 1);
	nametype = ft_strjoin(fname, type);
	free(fname);
	fd = open(nametype, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	free(nametype);
//	if (!fd || fd == -1)
//		valid_error(1);
	return (fd);
}

