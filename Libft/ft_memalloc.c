/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:09:51 by wvaara            #+#    #+#             */
/*   Updated: 2020/07/08 11:42:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size > 2147483647)
		return (NULL);
	if (!(str = (void *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	if (size > 0)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
