/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:24:14 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 13:33:41 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	ii;

	i = ft_strlen(s1);
	ii = ft_strlen(s2);
	if (!(fresh = (char *)malloc(sizeof(*fresh) * (i + ii + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
