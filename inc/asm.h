/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:35:14 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/14 18:42:41 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>

# define NL			0
# define STR		1
# define INS		2
# define LABEL		3
# define REG		4
# define SEP		5
# define DIR_L		6
# define DIR		7
# define INDIR		8
# define CMD		9

extern int	g_fd_new;
extern int	g_fd_read;

typedef struct		s_type
{
	int				count;
	char			type;
	char			*str;
}					t_type;

typedef struct		s_cmd
{
	int				id;
	char			*lbl;
	int				size;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef union		u_byte
{
	unsigned int	ints;
	unsigned char	chars[4];
}					u_byte;

int					lexical_er(int x, int i);

void				check_file(t_header *head, t_type *file, t_cmd *cmd);
int					check_line(t_header *head, t_type *file);
void				pars_line(char *line, int size, t_type *file);
int					pars_lbl(t_type *file, t_cmd *cmd);
int					output_oper(char *line);
int					pars_arg(t_type *file, int index, t_cmd *cmd);

int					read_arg(char *arg, int index);
char				arg_sum(char byte, int type);
int					write_arg(t_type *file, int tdir, t_cmd *cmd);

int					init_file(char *name);

int					make_bin(char *line, int size, int nll);
void				valid_error(int code);
void				print_magic(void);
unsigned int		reverse(unsigned int x, int cnt);
// cmd function

void				del_cmd(t_cmd *cmd, int count);
t_cmd				*create_cmd(t_type *file, t_header *head);
t_cmd				*new_cmd(t_cmd *last);
int					save_cmd(t_cmd *cmd, t_type *file);
int					roll_back(t_cmd **cmd);
int					search_lbl_prev(char *str, t_cmd *cmd);
int					search_lbl_next(char *str, t_cmd *cmd);
//valid functions

// void		*valid(char **list, t_type	**types);


char				**addlist(char **list, char *str);
char				**dellist(char **list);
char				*delcomment(char *str);
t_type				*read_file(char *name);
t_type				*settype(char **list);

t_type				*addtype(t_type *types, char *str, char type);
t_type				*cpytype(t_type *be, t_type *to, int x);
t_type				*deltype(t_type *types, int strs);
t_type				*setmemtype(t_type *types, int i);

char				*isins(char *str, int x);
char				*isindir(char *str, int x);

#endif
