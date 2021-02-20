/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:02:54 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:48 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_reset(t_data *data)
{
	data->i = 0;
	data->k = 0;
	data->y = data->y_start;
	data->x = data->x_start;
	data->pixel = 0;
	data->count = 0;
	data->y_count = 0;
}
