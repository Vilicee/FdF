/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:44:48 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/01 09:44:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	const char	*ptr;
	size_t		i;
	size_t		size;

	i = 0;
	size = len;
	if (*need == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && len > 0)
	{
		if (hay[i] == *need)
		{
			if (i + ft_strlen(need) > size)
				return (NULL);
			if (ft_strncmp(&hay[i], need, ft_strlen(need)) == 0)
			{
				ptr = &hay[i];
				return ((char *)ptr);
			}
		}
		i++;
		len--;
	}
	return (NULL);
}
