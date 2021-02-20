/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 09:02:03 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/07 10:52:58 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*string;
	long	nb;
	int		i;

	nb = n;
	i = ft_intlen(nb);
	if (!(string = (char *)malloc(sizeof(*string) * (i + 1))))
		return (NULL);
	ft_bzero(string, i);
	if (nb < 0)
	{
		string[0] = '-';
		nb = nb * -1;
	}
	string[i] = '\0';
	while (nb >= 0 && i > 0 && string[i - 1] != '-')
	{
		string[i - 1] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (string);
}
