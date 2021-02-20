/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:44:48 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 10:35:27 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*ptr;
	int			ret;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			ret = ft_strlen(needle);
			if (ft_strncmp(haystack, needle, ret) == 0)
			{
				ptr = haystack;
				return ((char *)ptr);
			}
		}
		haystack++;
	}
	return (NULL);
}
