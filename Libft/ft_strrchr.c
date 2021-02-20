/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:32:51 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 10:24:37 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ((char *)str);
	while (*str != '\0')
	{
		str++;
		ptr++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == c)
			return (ptr);
		if (c == '\0' && *(str + 1) == '\0')
		{
			ptr++;
			return (ptr);
		}
		str--;
		ptr--;
		i--;
	}
	return (NULL);
}
