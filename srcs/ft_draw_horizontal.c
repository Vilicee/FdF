/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:20:26 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_bigger(t_data *data)
{
	while (data->x != data->oldx)
	{
		if (data->k < (data->point[data->i].z - data->point[data->i - 1].z) + 1)
		{
			data->y++;
			data->k++;
		}
		if (data->k == (data->point[data->i].z - data->point[data->i - 1].z) + 1)
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

static void	ft_smaller(t_data *data)
{
	while (data->x != data->oldx)
	{
		if (data->point[data->i - 1].z - data->point[data->i].z == 1)
			data->x--;
		else
		{
			if (data->k < (data->point[data->i - 1].z - data->point[data->i].z) - 1)
			{
				data->y--;
				data->k++;
			}
			if (data->k == (data->point[data->i - 1].z - data->point[data->i].z) - 1)
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

static void	ft_equal(t_data *data)
{
	while (data->x != data->oldx)
	{
		data->x--;
		data->y++;
		if (ft_clip(data) == 1)
			data->pixel = ((data->y - data->offset) * data->line_byte) + (data->x * 4);
		ft_color_check(data);
		ft_calc_color(data);
	}
}

void		ft_draw_horizontal(t_data *data)
{
	data->tempx = data->x;
	data->tempy = data->y;
	data->current_color = data->point[data->i].color;
	if (data->i >= 2)
		data->prev_color = data->point[data->i - 1].color;
	if (data->point[data->i].z > data->point[data->i - 1].z && data->view == 1)
		ft_bigger(data);
	if (data->point[data->i].z < data->point[data->i - 1].z && data->view == 1)
		ft_smaller(data);
	if (data->point[data->i].z == data->point[data->i - 1].z || data->view == 0)
		ft_equal(data);
	data->k = 0;
	data->y = data->tempy;
	data->x = data->tempx;
}
