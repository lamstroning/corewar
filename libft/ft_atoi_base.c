/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:13:15 by tdontos-          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:18 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_len_num(int num, int base)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_atoi_base(int dec, int base)
{
	char	*res;
	int		i;
	int		mod;

	i = ft_len_num(dec, base);
	if (base > 16 || base < 2)
		return (NULL);
	if (dec < 0)
		dec *= -1;
	res = ft_strnew(i);
	res[--i] = '\0';
	while (dec != 0)
	{
		mod = dec % base;
		res[i--] = mod > 9 ? mod + 55 : mod + 48;
		dec /= base;
	}
	return (res);
}
