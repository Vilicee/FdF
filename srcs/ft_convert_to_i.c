/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:16:53 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 12:23:45 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_convert_to_i(char **str, t_data *data)
{
	int		i;
	int		ii;
	char	***line;

	i = 0;
	ii = 0;
	line = (char ***)malloc(sizeof(char**) * (data->y_axis + 1));
	while (str[i] != NULL)
	{
		line[ii] = ft_strsplit(str[i], ' ');
		ii++;
		i++;
	}
	line[ii] = NULL;
	ft_free_str(str);
	if (ft_create_int_arr(line, data) == -1)
		return (-1);
	return (0);
}
