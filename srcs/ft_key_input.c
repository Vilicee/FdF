/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:02:52 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_flat(t_data *data)
{
	if (data->view != 0)
	{
		data->view = 0;
		ft_reset(data);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 1600, 1000);
		data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
		ft_projection(data);
	}
}

static void	ft_back_to_3d(t_data *data)
{
	if (data->view != 1)
	{
		data->view = 1;
		ft_reset(data);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 1600, 1000);
		data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
		ft_projection(data);
	}
}

static void	ft_change_std_color(t_data *data, int key)
{
	if (key == 51)
		data->std_color = 0xFF6666;
	if (key == 52)
		data->std_color = 0xC39797;
	if (key == 53)
		data->std_color = 0x065535;
	if (key == 54)
		data->std_color = 0xEE82EE;
	ft_reset(data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1600, 1000);
	data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
	ft_projection(data);
}

static void	ft_zoom(t_data *data, int key)
{
	if (key == 45)
	{
		if (data->add > 1)
			data->add--;
	}
	if (key == 61)
	{
		if (data->add < 2147483647)
			data->add++;
	}
	ft_reset(data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1600, 1000);
	data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
	ft_projection(data);
}

int			ft_key_input(int key, t_data *data)
{
	if (key == ESCAPE_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == 49)
		ft_flat(data);
	if (key == 50)
		ft_back_to_3d(data);
	if (key == 51 || key == 52 || key == 53 || key == 54)
		ft_change_std_color(data, key);
	if (key == 45 || key == 61)
		ft_zoom(data, key);
	if ((key >= 65361 && key <= 65364) || key == FAST || key == SLOW)
		ft_move(data, key);
	return (0);
}
