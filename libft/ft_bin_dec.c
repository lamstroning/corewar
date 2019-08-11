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

int		bin_dec(int bin)
{
	int		res;
	int		pow;
	char	*bins;
	int		i;

	bins = ft_itoa(bin);
	i = ft_strlen(bins);
	pow = 0;
	res = 0;
	while (--i >= 0)
	{
		if (bins[i] != '0' && bins[i] != '1')
		{
			free(bins);
			return (-1);
		}
		res += (bins[i] - 48) * ft_pow(2, pow++);
	}
	free(bins);
	return (res);
}
