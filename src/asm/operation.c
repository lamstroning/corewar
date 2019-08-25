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

int		pars_lbl(t_type *file, t_cmd *cmd)
{
	int		index;

	while (file->type == NL)
		++file;
	index = output_oper(file->str);
	if (index == -1)
		return (-1);
	return (pars_arg(file, index, cmd));

}

int		output_oper(char *line)
{
	int		i;

	i = -1;
	while (++i < REG_NUMBER)
	{
		if (ft_strcmp(line, g_op_tab[i].name) == 0)
			return(i);
	}
	return (-1);
}

int		pars_arg(t_type *file, int index, t_cmd *cmd)
{
	int		i;
	char	bin;

//	if (index < 10)
//		ft_putchar_fd((char)0, g_fd_new);
	ft_putchar_fd((char)index + 1, g_fd_new);
	i = -1;
	while (file[++i].type != NL)
	{
		if (file[i].type == REG)
			bin = arg_sum(bin, T_REG);
		else if (file[i].type == DIR)
			bin = arg_sum(bin, T_DIR);
		else if (file[i].type == INDIR)
			bin = arg_sum(bin, T_IND);
	}
	bin = bin << (3 - g_op_tab[index].nb_arg) * 2;
	if (g_op_tab[index].nb_arg > 1)
		make_bin(&bin, 1, 0);
	return (write_arg(file, g_op_tab[index].label == 0 ? 4 : 2, cmd));
}
