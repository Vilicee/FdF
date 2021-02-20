/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:02:53 by wvaara            #+#    #+#             */
/*   Updated: 2021/01/05 14:23:50 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	result(char **str, char **line, int ret)
{
	int		len;
	char	*temp;

	len = 0;
	if (ret >= 0 && *str != NULL)
	{
		while ((*str)[len] != '\n' && (*str)[len] != '\0')
			len++;
		if ((*str)[len] == '\n')
		{
			*line = ft_strsub(*str, 0, len);
			temp = ft_strdup(&(*str)[len + 1]);
			free(*str);
			*str = temp;
			if ((*str)[0] == '\0')
				ft_strdel(str);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strdel(str);
		}
		return (1);
	}
	return (0);
}

int			ft_gnl(const int fd, char **line)
{
	int			ret;
	static char	*str[4096];
	char		buf[GNL_BUFF_SIZE + 1];
	char		*temp;

	if (line == NULL)
		return (-1);
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (result(&str[fd], line, ret));
}
