/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:30:30 by kmurch            #+#    #+#             */
/*   Updated: 2019/08/16 20:17:54 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char	*delcomment(char *str)
{
	char	*ret;
	int		x;
	int		i;

	x = -1;
	while (str[++x] && str[x] != COMMENT_CHAR
			&& str[x] != ALT_COMMENT_CHAR)
		;
	if (!x || !(ret = (char *)malloc(sizeof(char) * (x + 1))))
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (++i < x)
		ret[i] = str[i];
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	*command(char *str, int x)
{
	int		i;
	char	f;

	i = -1;
	f = 0;
	while (NAME_CMD_STRING[++i])
		if (NAME_CMD_STRING[i] != str[i + x])
			f = 1;
	if (!f)
		return (NAME_CMD_STRING);
	i = -1;
	f = 0;
	while (COMMENT_CMD_STRING[++i])
		if (COMMENT_CMD_STRING[i] != str[i + x])
			f = 1;
	if (!f)
		return (COMMENT_CMD_STRING);
	return (NULL);
}

char	*addcstr(char *str, char c)
{
	char	*ret;
	int		x;
	int		len;

	len = ft_strlen(str);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 2))))
	{
		ft_strdel(&str);
		return (str);
	}
	x = -1;
	while (str[++x])
		ret[x] = str[x];
	ret[x] = c;
	ret[x + 1] = '\0';
	ft_strdel(&str);
	return (ret);
}

int		islchar(char c)
{
	int	x;

	x = -1;
	while (LABEL_CHARS[++x])
		if (c == LABEL_CHARS[x])
			return (1);
	return (0);
}

char	*islabel(char *str, int x)
{
	char	*ret;

	if (!(ret = (char *)ft_memalloc(sizeof(char))))
		return (ret);
	x--;
	while (str[++x] && islchar(str[x]))
		ret = addcstr(ret, str[x]);
	if (str[x] && str[x] == LABEL_CHAR)
		return (ret);
	ft_strdel(&ret);
	return (ret);
}

int		isvalidend(char c)
{
	if (c == ' ' || c == '\t' || c == '\0'
			|| c == COMMENT_CHAR || c == ALT_COMMENT_CHAR
			|| c == DIRECT_CHAR || c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

char	*isreg(char *str, int x)
{
	char *ret;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char))))
		return (ret);
	if (str[x + 1] && str[x + 1] >= '0' && str[x + 1] <= '9'
			&& isvalidend(str[x + 2]))
	{
		ret = addcstr(ret, 'r');
		ret = addcstr(ret, str[x + 1]);
		return (ret);
	}
	if (str[x + 1] && str[x + 1] >= '0' && str[x + 1] <= '9'
			&& str[x + 2] && str[x + 2] >= '0' && str[x + 2] <= '9'
			&& isvalidend(str[x + 3]))
	{
		ret = addcstr(ret, 'r');
		ret = addcstr(ret, str[x + 1]);
		ret = addcstr(ret, str[x + 2]);
		return (ret);
	}
	ft_strdel(&ret);
	return (ret);
}

char	*isdir(char *str, int x)
{
	char	*ret;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char))))
		return (ret);
	if (str[++x] && str[x] == LABEL_CHAR)
	{
		while (str[++x] && islchar(str[x]))
			ret = addcstr(ret, str[x]);
		ret = addcstr(ret, ' ');
		return (ret);
	}
	x--;
	while (str[++x] && str[x] >= '0' && str[x] <= '9')
		ret = addcstr(ret, str[x]);
	if (ft_strlen(ret) < 1)
		ft_strdel(&ret);
	return (ret);
}

char	*isindir(char *str, int x)

{
	char *ret;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char))))
		return (ret);
	if (str[x] && str[x] == LABEL_CHAR)
	{
		while (str[++x] && islchar(str[x]))
			ret = addcstr(ret, str[x]);
		return (ret);
	}
	x--;
	while (str[++x] && str[x] >= '0' && str[x] <= '9')
		ret = addcstr(ret, str[x]);
	if (ft_strlen(ret) < 1)
		ft_strdel(&ret);
	return (ret);
}

char	*isins(char *str, int x)
{
	char *ret;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char))))
		return (ret);
	x--;
	while (str[++x] && islchar(str[x]))
		ret = addcstr(ret, str[x]);
	if (isvalidend(str[x]))
		return (ret);
	ft_strdel(&ret);
	return (ret);
}

t_type	*settype(char **list)
{
	t_type	*types;
	char	mod;
	char	*str;
	int		i;
	int		j;

	i = -1;
	mod = 0;
	types = NULL;
	types = addtype(types, "NL", NL);
	while (list[++i])
	{
		j = -1;
		while (list[i][++j])
		{
			if (mod == 1 && list[i][j] == '\"')
			{
				types = addtype(types, str, STR);
				ft_strdel(&str);
				mod = 0;
				continue ;
			}
			if (mod == 1)
			{
				str = addcstr(str, list[i][j]);
				continue ;
			}
			if (list[i][j] == COMMENT_CHAR || list[i][j] == ALT_COMMENT_CHAR)
				break ;
			if (!mod && list[i][j] == SEPARATOR_CHAR)
			{
				types = addtype(types, ",", SEP);
				continue ;
			}
			if (!mod && list[i][j] == DIRECT_CHAR)
			{
				if ((str = isdir(list[i], j)))
				{
					types = addtype(types, str, DIR);
					j += ft_strlen(str);
					ft_strdel(&str);
					continue ;
				}
			}
			if (!mod && (list[i][j] == LABEL_CHAR ||
						(list[i][j] >= '0' && list[i][j] <= '9')))
			{
				if ((str = isindir(list[i], j)))
				{
					types = addtype(types, str, INDIR);
					j += ft_strlen(str);
					ft_strdel(&str);
					continue ;
				}
			}
			if (!mod && islchar(list[i][j]))
			{
				if ((str = islabel(list[i], j)))
				{
					types = addtype(types, str, LABEL);
					j += ft_strlen(str);
					ft_strdel(&str);
					continue ;
				}
			}
			if (!mod && list[i][j] == 'r')
			{
				if ((str = isreg(list[i], j)))
				{
					types = addtype(types, str, REG);
					j += ft_strlen(str) - 1;
					ft_strdel(&str);
					continue ;
				}
			}
			if (!mod && islchar(list[i][j]))
			{
				if ((str = isins(list[i], j)))
				{
					types = addtype(types, str, INS);
					j += ft_strlen(str);
					ft_strdel(&str);
					continue ;
				}
			}
			if (!mod && (list[i][j] == ' ' || list[i][j] == '\t'))
				continue ;
			if (!mod && list[i][j] == '.')
			{
				if (!command(list[i], j))
				{
					deltype(types, types[0].count);
					lexical_er(i, j);
					return ((types = 0));
				}
				else
					types = addtype(types, command(list[i], j), CMD);
				j += ft_strlen(command(list[i], j));
			}
			if (!mod && list[i][j] == '\"')
			{
				str = (char *)malloc(sizeof(char));
				mod = 1;
			}
		}
		if (!mod && types[types[0].count - 1].type != NL)
			types = addtype(types, "NL", NL);
	}
	return (types);
}

// void	*valid(char **list, t_type	*types;)
// {
// 	types = settype(list);
// 	return (list);
// }
