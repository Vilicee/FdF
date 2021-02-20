/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:01:12 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:35:03 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (len > 0)
	{
		while (src[i] != '\0' && len > 1)
		{
			dst[i] = src[i];
			i++;
			len--;
		}
		dst[i] = '\0';
		ret = ft_strlen(src);
		return (ret);
	}
	if (len <= 0)
		ret = ft_strlen(src);
	return (ret);
}
