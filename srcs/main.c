/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:37:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:25:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_exit_invalid(void)
{
	ft_putendl("Invalid map, exciting program");
	return (-1);
}

static int	ft_exit_readerr(void)
{
	ft_putendl("Error in open, invalid or missing file");
	return (-1);
}

static int	ft_exit_usage(void)
{
	ft_putendl("usage: ./fdf input_file");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		return (ft_exit_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_exit_readerr());
	if ((ft_fdf(&data, argv[1], fd)) == -1)
		return (ft_exit_invalid());
	return (0);
}
