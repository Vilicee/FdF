/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:13:57 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_calc_color(t_data *data)
{
	if (data->endian == 1)
	{
		data->buf[data->pixel + 0] = (data->pixelcolor >> 24);
		data->buf[data->pixel + 1] = (data->pixelcolor >> 16) & 0xFF;
		data->buf[data->pixel + 2] = (data->pixelcolor >> 8) & 0xFF;
		data->buf[data->pixel + 3] = (data->pixelcolor) & 0xFF;
	}
	if (data->endian == 0)
	{
		data->buf[data->pixel + 0] = (data->pixelcolor) & 0xFF;
		data->buf[data->pixel + 1] = (data->pixelcolor >> 8) & 0xFF;
		data->buf[data->pixel + 2] = (data->pixelcolor >> 16) & 0xFF;
		data->buf[data->pixel + 3] = (data->pixelcolor >> 24);
	}
}
