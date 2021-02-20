/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:08:26 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:42 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_part_one(t_data *data)
{
	while (data->i < data->x_axis * data->y_axis)
	{
		if (data->point[data->i].z != 0 && data->view == 1)
			data->offset = data->point[data->i].z * data->add;
		else
			data->offset = 0;
		if (data->point[data->i].color == data->point[data->i + 1].color)
			data->pixelcolor = data->point[data->i].color;
		else
			data->pixelcolor = data->std_color;
		if (ft_clip(data) == 1)
		{
			data->pixel = ((data->y - data->offset) * data->line_byte) + (data->x * 4);
			ft_calc_color(data);
		}
		if (data->i > 0 && data->i % data->x_axis != 0)
			ft_draw_horizontal(data);
		data->oldx = data->x;
		if (data->x == (data->x_axis - 1) * data->add + data->x_start + (data->add * data->count))
		{
			data->count++;
			data->y = data->y_start + data->add * data->count;
			data->x = data->x_start + data->add * data->count;
		}
		else
		{
			data->x = data->x + data->add;
			data->y = data->y - data->add;
		}
		data->i++;
	}
}

static void	ft_part_two(t_data *data)
{
	int a;

	a = data->y_axis - 1;
	while (data->i < data->x_axis * data->y_axis)
	{
		if (data->point[data->i].z != 0 && data->view == 1)
			data->offset = data->point[data->i].z * data->add;
		else
			data->offset = 0;
		if (data->i > 0)
			ft_draw_vertical(data);
		if (data->i == data->x_axis * a + data->y_count && data->i != data->y_axis * data->x_axis - 1)
		{
			data->y_count++;
			data->i = data->y_count;
			data->x = data->x_start + (data->add * data->y_count);
			data->y = data->y_start - (data->add * data->y_count);
		}
		data->x = data->x + data->add;
		data->y = data->y + data->add;
		data->i = data->i + data->x_axis;
	}
}

void		ft_projection(t_data *data)
{
	ft_part_one(data);
	ft_reset(data);
	ft_part_two(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, &ft_key_input, data);
	mlx_loop(data->mlx);
}
