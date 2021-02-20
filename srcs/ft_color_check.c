/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:02:10 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color_check(t_data *data)
{
	if (data->current_color == data->prev_color)
		data->pixelcolor = data->current_color;
	else
		data->pixelcolor = data->std_color;
}
