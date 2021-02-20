/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:51:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/20 13:29:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESCAPE_KEY 65307
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define FAST 102
# define SLOW 115
# include "../Libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_point
{
	char			*hex;
	int				color;
	int				z;
}					t_point;

typedef struct		s_data
{
	int				speed;
	int				view;
	int				std_color;
	int				y_count;
	int				current_color;
	int				prev_color;
	int				i;
	int				ii;
	int				iii;
	int				x_start;
	int				y_start;
	int				count;
	int				offset;
	int				k;
	int				x;
	int				y;
	int				oldx;
	int				oldy;
	int				tempx;
	int				tempy;
	int				tempoldx;
	int				tempoldy;
	int				pixel;
	int				y_axis;
	int				x_axis;
	int				add;
	int				pixel_byte;
	int				line_byte;
	int				endian;
	int				pixelcolor;
	void			*mlx;
	void			*img;
	void			*win;
	char			*buf;
	t_point			point[500000];
}					t_data;

int					ft_key_input(int key, t_data *dt);
int					ft_fdf(t_data *dt, char *argv, int fd);
int					ft_save_string(char *argv, t_data *dt);
int					ft_convert_to_i(char **str, t_data *dt);
int					ft_create_int_arr(char ***str, t_data *dt);
int					ft_clip(t_data *dt);
void				ft_free_str(char **str);
void				ft_free_line(char ***line);
void				ft_color_set(t_data *dt);
void				ft_calc_color(t_data *dt);
void				ft_projection(t_data *dt);
void				ft_draw_horizontal(t_data *dt);
void				ft_draw_vertical(t_data *dt);
void				ft_color_check(t_data *dt);
void				ft_reset(t_data *dt);
void				ft_set_box_size(t_data *dt);
void				ft_move(t_data *dt, int key);

#endif
