/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:29:43 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:43:40 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*map;
	int		ret;
	int		i;

	i = 0;
	ret = ft_strlen(str);
	if (!(map = (char *)malloc(sizeof(*map) * (ret + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		map[i] = f(str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
