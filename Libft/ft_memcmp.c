/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:47:33 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:24:46 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ret;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ret = 0;
	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr != *ptr1)
			return (*ptr - *ptr1);
		ptr++;
		ptr1++;
		n--;
	}
	return (ret);
}
