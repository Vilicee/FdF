/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:48:07 by wvaara            #+#    #+#             */
/*   Updated: 2020/06/30 16:43:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordlength(const char *str, char c)
{
	size_t count;

	count = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
