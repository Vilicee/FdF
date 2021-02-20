/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:16:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:08 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_fdf(t_data *data, char *argv, int fd)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	data->speed = 30;
	while (ft_gnl(fd, &line) > 0)
	{
		if (line[0] != '\n')
			count++;
		free(line);
	}
	if (count == 0)
		return (-1);
	data->y_axis = count;
	data->view = 1;
	if (ft_save_string(argv, data) == -1)
		return (-1);
	return (0);
}
