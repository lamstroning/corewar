/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:48:12 by tdontos-          #+#    #+#             */
/*   Updated: 2019/08/03 18:48:14 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		make_bin(char *line, int size, int nll)
{
	int		i;

	if (size == 0)
		return (0);
	i = -1;
	while (++i < size)
		ft_putchar_fd(line[i], g_fd_new);
	while (++i <= size + nll)
		ft_putchar_fd(0, g_fd_new);
	return (1);
}

void	valid_error(int code)
{
	if (code == 1)
		ft_putstr_fd("wrong file", 2);
	if (code == 2)
		ft_putstr_fd("wrong name of the champion", 2);
	exit(1);
}

void	print_magic(void)
{
	u_byte	magic;

	magic.ints = COREWAR_EXEC_MAGIC;
	ft_putchar_fd(magic.chars[3], g_fd_new);
	ft_putchar_fd(magic.chars[2], g_fd_new);
	ft_putchar_fd(magic.chars[1], g_fd_new);
	ft_putchar_fd(magic.chars[0], g_fd_new);
}
