/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_int_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:37:13 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:50 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_input_ok(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1600, 1000, "FdF window");
	data->img = mlx_new_image(data->mlx, 1600, 1000);
	data->buf = mlx_get_data_addr(data->img, &data->pixel_byte, &data->line_byte, &data->endian);
	data->i = 0;
	data->ii = 0;
	ft_color_set(data);
	data->i = 0;
	ft_set_box_size(data);
	ft_reset(data);
	ft_projection(data);
}

static int	ft_check_len(char ***str)
{
	int x_axis;
	int i;
	int check;

	i = 0;
	x_axis = 0;
	check = 0;
	while (str[i][check] != NULL)
		check++;
	while (str[i] != NULL)
	{
		while (str[i][x_axis] != NULL)
			x_axis++;
		if (check != x_axis)
			return (-1);
		i++;
		check = x_axis;
		if (str[i] != NULL)
			x_axis = 0;
	}
	return (x_axis);
}

static void	ft_substring(char ***str, t_data *data)
{
	free(data->point[data->k].hex);
	data->point[data->k].hex = ft_strsub(&str[data->i][data->ii][data->iii], 1, 8);
}

static int	ft_create_array(char ***str, t_data *data)
{
	while (data->i < data->y_axis)
	{
		while (data->ii < data->x_axis)
		{
			while (str[data->i][data->ii][data->iii] != '\0')
			{
				if (str[data->i][data->ii][data->iii] == ',')
					ft_substring(str, data);
				data->iii++;
			}
			data->point[data->k].z = ft_atoi(str[data->i][data->ii]);
			data->iii = 0;
			data->ii++;
			data->k++;
		}
		data->i++;
		data->ii = 0;
	}
	ft_free_line(str);
	ft_input_ok(data);
	return (0);
}

int			ft_create_int_arr(char ***str, t_data *data)
{
	data->i = 0;
	data->ii = 0;
	data->iii = 0;
	data->k = 0;
	data->std_color = 0xEE82EE;
	if ((data->i = ft_check_len(str)) == -1)
		return (-1);
	data->x_axis = data->i;
	if (data->x_axis * data->y_axis > 500000)
		return (-1);
	data->i = 0;
	while (data->i < data->y_axis * data->x_axis)
	{
		data->point[data->i].color = data->std_color;
		data->point[data->i].hex = ft_strdup("empty");
		data->i++;
	}
	data->i = 0;
	if (ft_create_array(str, data) == -1)
		return (-1);
	return (0);
}
