/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:42:50 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/25 08:50:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub != NULL)
	{
		while (str[start] != '\0' && len > 0)
		{
			sub[i] = str[start];
			start++;
			i++;
			len--;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
