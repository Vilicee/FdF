/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:25:24 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/12 13:52:49 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t len)
{
	int i;
	int ret;

	i = 0;
	ret = ft_strlen(str);
	if (ret < len)
		return (ret);
	if (ret > len)
	{
		while (len > 0)
		{
			if (str[i] == '\0')
				return (i + len);
			len--;
			i++;
		}
		ret(len);
	}
}
