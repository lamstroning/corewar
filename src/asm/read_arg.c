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

int		read_arg(char *arg, int index)
{
	char	**res;
	int		i;
	char	bin;
	char	*line;

	i = -1;
	bin = '\0';
	res = ft_strsplit(arg, SEPARATOR_CHAR);
	while (++i < g_op_tab[index].nb_arg)
	{
		if (res[i] == NULL)
			valid_error(1);
		line = ft_strtrim(res[i]);
		if (ft_strchr(line, DIRECT_CHAR) != NULL)
			bin = arg_sum(bin, T_DIR);
		else if (line[0] == 'r')
			bin = arg_sum(bin, T_REG);
		else
			bin = arg_sum(bin, T_IND);
		free(line);
	}
	bin = bin << (3 - g_op_tab[index].nb_arg) * 2;
	make_bin(&bin, 8);
	return (0);
}

char		arg_sum(char byte, int type)
{
	byte = byte | type;
	byte = byte << 2;
	return (byte);
}

void	write_arg(char *arg)
{
	arg++;
}

int		read_name(char *name)
{
	name = NULL;
	return (0);
}
