/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:06:53 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/01 08:31:21 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(const char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - 1] != c && i != 0)
			count++;
		i++;
		if (str[i] == '\0' && str[i - 1] != c)
			count++;
	}
	return (count);
}
