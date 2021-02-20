/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 10:33:59 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 09:28:27 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (dest[i] != '\0')
		i++;
	while (src[ii] != '\0' && n > 0)
	{
		dest[i] = src[ii];
		i++;
		ii++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
