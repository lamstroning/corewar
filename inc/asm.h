/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:35:14 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/03 15:35:17 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>

int		init_file(char *name);

int		make_bin(char *line, int fd, int size);
void	valid_error(int code);
void	print_magic(int fd);

void	read_file(t_header *head, int fd, char *name);
int		check_line(t_header *head, char *line, int fd);
int		pars_name(t_header *head, char *name, int fd);
int		pars_comment(t_header *head, char *name, int fd);
char	*parse_string(char *str);

#endif
