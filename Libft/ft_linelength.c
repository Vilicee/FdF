/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:48:07 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/07 16:58:16 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_linelength(const char *str, char c)
{
	size_t count;

	count = 0;
	if (*str != c)
	{
		while (*str != c && *str != '\0')
		{
			str++;
			count++;
		}
		return (count);
	}
	if (*str == c)
		count++;
	return (count);
}
