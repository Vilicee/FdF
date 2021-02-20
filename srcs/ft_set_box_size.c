/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_box_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:08:43 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:25:01 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_set_box_size(t_data *data)
{
	if (data->x_axis <= 25 || data->y_axis <= 25)
		data->add = 20;
	if ((data->x_axis >= 26 && data->x_axis <= 50) || (data->y_axis >= 26 && data->y_axis <= 50))
		data->add = 15;
	if ((data->x_axis > 50 && data->x_axis < 150) || (data->y_axis >= 50 && data->y_axis <= 150))
		data->add = 5;
	if (data->x_axis >= 150 || data->y_axis >= 150)
		data->add = 2;
	data->y_start = 500;
	data->x_start = 50;
	if (data->pixel_byte != 32)
		data->pixelcolor = mlx_get_color_value(data->mlx, data->pixelcolor);
}
