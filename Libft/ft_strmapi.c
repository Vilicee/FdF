/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:29:51 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:53:25 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				ret;
	char			*map;

	i = 0;
	ret = ft_strlen(str);
	if (!(map = (char *)malloc(sizeof(*map) * (ret + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		map[i] = f(i, str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
