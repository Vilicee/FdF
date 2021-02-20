/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:09:08 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_bigger(t_data *data)
{
	while (data->x > data->tempoldx)
	{
		if (data->point[data->i].z - data->point[data->i - data->x_axis].z == 1)
			data->x--;
		else
		{
			if (data->k < data->point[data->i].z - data->point[data->i - data->x_axis].z - 1)
			{
				data->y++;
				data->k++;
			}
			if (data->k == data->point[data->i].z - data->point[data->i - data->x_axis].z - 1)
			{
				data->x--;
				data->k = 0;
			}
		}
		if (ft_clip(data) == 1)
			data->pixel = ((data->y - data->offset) * data->line_byte) + (data->x * 4);
		ft_color_check(data);
		ft_calc_color(data);
	}
}

static void	ft_smaller(t_data *data)
{
	while (data->x > data->tempoldx)
	{
		if (data->k < (data->point[data->i - data->x_axis].z - data->point[data->i].z) + 1)
		{
			data->y--;
			data->k++;
		}
		if (data->k == (data->point[data->i - data->x_axis].z - data->point[data->i].z) + 1)
		{
			data->x--;
			data->k = 0;
		}
		if (ft_clip(data) == 1)
			data->pixel = ((data->y - data->offset) * data->line_byte) + (data->x * 4);
		ft_color_check(data);
		ft_calc_color(data);
	}
}

static void	ft_equal(t_data *data)
{
	while (data->y > data->tempoldy)
	{
		data->x--;
		data->y--;
		if (ft_clip(data) == 1)
			data->pixel = ((data->y - data->offset) * data->line_byte) + (data->x * 4);
		ft_color_check(data);
		ft_calc_color(data);
	}
}

static void	ft_set_xy(t_data *data)
{
	if (data->view == 1)
	{
		data->tempoldx = data->x - data->add;
		if (data->point[data->i - data->x_axis].z == data->point[data->i].z)
			data->tempoldy = data->y - data->add;
		else
			data->tempoldy = data->y - data->point[data->i - data->x_axis].z * data->add;
	}
	if (data->view == 0)
		data->tempoldy = data->y - data->add;
}

void		ft_draw_vertical(t_data *data)
{
	data->tempx = data->x;
	data->tempy = data->y;
	data->current_color = data->point[data->i].color;
	data->prev_color = data->point[data->i - data->x_axis].color;
	ft_set_xy(data);
	if (data->point[data->i].z > data->point[data->i - data->x_axis].z && data->view == 1)
		ft_bigger(data);
	if (data->point[data->i].z < data->point[data->i - data->x_axis].z && data->view == 1)
		ft_smaller(data);
	if (data->point[data->i].z == data->point[data->i - data->x_axis].z || data->view == 0)
		ft_equal(data);
	data->k = 0;
	data->y = data->tempy;
	data->x = data->tempx;
}
