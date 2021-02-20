/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:21:38 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 10:16:10 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = ((char *)str);
	while (*str != '\0')
	{
		if (*str == c)
			return (ptr);
		if (c == '\0' && *(str + 1) == '\0')
		{
			ptr++;
			return (ptr);
		}
		str++;
		ptr++;
	}
	if (*str == '\0' && c == '\0')
		return (ptr);
	return (NULL);
}
