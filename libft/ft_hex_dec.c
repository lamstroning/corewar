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

int		hex_dec(char *hex)
{
	int		len;
	int		i;
	int		res;

	if (hex == NULL)
		return (0);
	i = ft_strchr(hex, 'X') != NULL || ft_strchr(hex, 'x') != NULL ? 1 : -1;
	res = 0;
	len = ft_strlen(hex);
	while (++i < len)
	{
		if (ft_isdigit(hex[i]))
			res += (hex[i] - 48) * ft_pow(16, len - i - 1);
		else
		{
			hex[i] = ft_toupper(hex[i]);
			res += (hex[i] - 55) * ft_pow(16, len - i - 1);
		}
	}
	ft_strdel(&hex);
	return (res);
}
