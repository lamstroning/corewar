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

extern int	g_fd_new;
extern int	g_fd_read;

typedef struct		s_lbl
{
	char			*name;
	char			*cmd;
	struct s_lbl	*next;
}					t_lbl;

int			init_file(char *name);

int			make_bin(char *line, int size);
void		valid_error(int code);
void		print_magic(void);

char		**addlist(char **list, char *str);
char		**dellist(char **list);
char		**read_file(void);

void		check_file(t_header *head, char **file);
int			check_line(t_header *head, char *line, t_lbl *lbl);
int			pars_line(char *line, char *name, int size);
char		*parse_string(char *str);
int			pars_lbl(char *line, t_lbl *lbl);
char		*save_lbl_cmd(char	*line);
int			output_oper(char *line);
int			check_lbl(char *line, t_lbl *lbl);
int			pars_arg(char *line, int index);

int			read_name(char *name);
int			read_arg(char *arg, int index);
char		arg_sum(char byte, int type);
void		write_arg(char *arg);

#endif
