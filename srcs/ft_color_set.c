/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:11:58 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:38 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color_set(t_data *data)
{
	while (data->i < data->y_axis * data->x_axis)
	{
		if (ft_strcmp(data->point[data->i].hex, "0xFFFFFF") == 0)
			data->point[data->i].color = WHITE;
		if (ft_strcmp(data->point[data->i].hex, "0xFFFF00") == 0)
			data->point[data->i].color = YELLOW;
		if (ft_strcmp(data->point[data->i].hex, "0xFF0000") == 0)
			data->point[data->i].color = RED;
		if (ft_strcmp(data->point[data->i].hex, "0x00FF00") == 0)
			data->point[data->i].color = GREEN;
		if (ft_strcmp(data->point[data->i].hex, "0x00FFFF") == 0)
			data->point[data->i].color = CYAN;
		if (ft_strcmp(data->point[data->i].hex, "0xFF00FF") == 0)
			data->point[data->i].color = MAGENTA;
		if (ft_strcmp(data->point[data->i].hex, "0x0000FF") == 0)
			data->point[data->i].color = BLUE;
		if (ft_strcmp(data->point[data->i].hex, "0x000000") == 0)
			data->point[data->i].color = BLACK;
		free(data->point[data->i].hex);
		data->i++;
	}
}
