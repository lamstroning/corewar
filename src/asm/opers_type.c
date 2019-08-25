/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:21:56 by kmurch            #+#    #+#             */
/*   Updated: 2019/08/14 16:15:59 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_type	*setmemtype(t_type *types, int i)
{
	int x;

	x = -1;
	if (!(types = (t_type *)malloc(sizeof(t_type) * i)))
		return (types);
	return (types);
}

t_type	*deltype(t_type *types, int strs)
{
	int x;

	x = -1;
	while (++x < strs)
		ft_strdel(&types[x].str);
	free(types);
	return (types);
}

t_type	*cpytype(t_type *be, t_type *to, int x)
{
	int i;

	i = -1;
	while (++i < x)
	{
		to[i].str = ft_strdup(be[i].str);
		to[i].type = be[i].type;
	}
	return (to);
}

t_type	*addtype(t_type *types, char *str, char type)
{
	static int	count = 0;
	static int	strs = 0;
	t_type		*buff;

	if (count == 0 && (count = 1) &&
			!(types = (t_type *)malloc(sizeof(t_type))))
		return (0);
	buff = NULL;
	if (strs + 1 == count)
	{
		count = count * 2;
		if (!(buff = setmemtype(buff, count)))
			return (deltype(types, strs));
		buff = cpytype(types, buff, strs);
		deltype(types, strs);
		if (!(types = setmemtype(types, count)))
			return (deltype(buff, strs));
		types = cpytype(buff, types, strs);
		deltype(buff, strs);
	}
	types[strs++].str = ft_strdup(str);
	types[strs - 1].type = type;
	types[0].count = strs;
	return (types);
}
