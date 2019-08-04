/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:16:02 by tdontos-          #+#    #+#             */
/*   Updated: 2019/03/24 13:20:58 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_chr(char *str, char s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (ft_strchr(str, s) != NULL)
		i = ft_strchr(str, s) - str;
	if (i <= 0)
		i = ft_strlen(str);
	tmp = ft_strnew(i + 1);
	while (i > 0)
	{
		i--;
		tmp[i] = str[i];
	}
	return (tmp);
}
