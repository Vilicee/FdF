/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:53:23 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:14 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_line(char ***line)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (line[i] != NULL)
	{
		while (line[i][ii] != NULL)
		{
			free(line[i][ii]);
			ii++;
		}
		free(line[i]);
		i++;
		ii = 0;
	}
	free(line);
}
