/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:57:05 by kmurch            #+#    #+#             */
/*   Updated: 2019/08/14 17:25:08 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int	lexical_er(int	x, int i)
{
	i++;
	x++;
	ft_putstr_fd("Lexical error at [", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(i, 2);
	ft_putendl_fd("]", 2);
	return (0);
}
