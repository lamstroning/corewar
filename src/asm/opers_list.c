/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:59:57 by kmurch            #+#    #+#             */
/*   Updated: 2019/08/11 16:38:20 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char	**setmem(char **list, int i)
{
	int x;

	x = -1;
	if (!(list = (char **)malloc(sizeof(char *) * i)))
		return (list);
	while (++x < i)
		list[x] = 0;
	return (list);
}

char	**dellist(char **list)
{
	int	x;

	x = -1;
	while (list[++x])
		ft_strdel(&list[x]);
	free(list);
	return (list);
}

char	**cpylist(char **be, char **to, int x)
{
	int	i;

	i = -1;
	while (++i < x)
		to[i] = ft_strdup(be[i]);
	to[i] = 0;
	be[i] = 0;
	return (to);
}

char	**addlist(char **list, char *str)
{
	static int	count = 0;
	static int	strs = 0;
	char		**buff;

	if (count == 0 && (count = 1) &&
			!(list = (char **)malloc(sizeof(char *))))
		return (0);
	buff = NULL;
	if (strs + 1 == count)
	{
		count = count * 2;
		if (!(buff = setmem(buff, count)))
			return (dellist(list));
		buff = cpylist(list, buff, strs);
		dellist(list);
		if (!(list = setmem(list, count)))
			return (dellist(buff));
		list = cpylist(buff, list, strs);
		dellist(buff);
	}
	list[strs++] = ft_strdup(str);
	list[strs] = 0;
	return (list);
}
