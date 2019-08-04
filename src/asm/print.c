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

int		make_bin(char *line, int fd, int size)
{
	int		i;

	if (size % 8 != 0)
		line = ft_addnchr_e(line, '\0', 8 - (size % 8));
	if (size == 0)
		return (0);
	i = -1;
	while (++i <= size + 3)
		ft_putchar_fd(line[i], fd);
	return (1);
}

void	valid_error(int code)
{
	if (code == 1)
		ft_putstr("wrong file");
	if (code == 2)
		ft_putstr("wrong name of the champion");
	exit(1);
}

void	print_magic(int fd)
{
	ft_putchar_fd((char)0, fd);
	ft_putchar_fd((char)234, fd);
	ft_putchar_fd((char)131, fd);
	ft_putchar_fd((char)243, fd);
}
