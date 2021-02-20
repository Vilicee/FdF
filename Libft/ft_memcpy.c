/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:31:50 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:27:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*srce;
	unsigned char	*dest;

	srce = (unsigned char*)src;
	dest = (unsigned char*)dst;
	i = 0;
	if (dst || src)
	{
		while (n > 0)
		{
			dest[i] = srce[i];
			i++;
			n--;
		}
	}
	return (dst);
}
