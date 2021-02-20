/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 09:49:49 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 12:04:55 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *strptr;

	strptr = (unsigned char *)str;
	while (n > 0)
	{
		if (*strptr == (unsigned char)c)
			return ((void *)strptr);
		strptr++;
		n--;
	}
	return (NULL);
}
