/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:33:08 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:34 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_speed(t_data *data, int key)
{
	if (key == FAST)
	{
		if (data->speed < 60)
			data->speed = data->speed + 5;
	}
	if (key == SLOW)
	{
		if (data->speed > 5)
			data->speed = data->speed - 5;
	}
}

void		ft_move(t_data *data, int key)
{
	ft_speed(data, key);
	if (key == DOWN)
		data->y_start = data->y_start - data->speed;
	if (key == UP)
		data->y_start = data->y_start + data->speed;
	if (key == RIGHT)
		data->x_start = data->x_start - data->speed;
	if (key == LEFT)
		data->x_start = data->x_start + data->speed;
	ft_reset(data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1600, 1000);
	data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
	ft_projection(data);
}
