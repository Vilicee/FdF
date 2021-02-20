/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:49:31 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:24:55 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check_str(char **str)
{
	int i;
	int ii;
	int count;

	i = 0;
	ii = 0;
	count = 0;
	while (str[i] != NULL)
	{
		while (str[i][ii] != '\0')
		{
			if (ft_isdigit(str[i][ii]))
				count++;
			ii++;
		}
		i++;
		ii = 0;
	}
	if (str[0][0] == '\0' || count == 0)
	{
		ft_free_str(str);
		return (-1);
	}
	return (0);
}

int			ft_save_string(char *file, t_data *data)
{
	char	**str;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!(str = (char **)malloc(sizeof(char*) * (data->y_axis + 1))))
		return (-1);
	while (ft_gnl(fd, &line) > 0)
	{
		if (line[0] != '\n')
		{
			str[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	str[i] = NULL;
	if (ft_check_str(str) == -1)
		return (-1);
	if (ft_convert_to_i(str, data) == -1)
		return (-1);
	return (0);
}
