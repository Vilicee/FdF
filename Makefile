# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 09:56:51 by wvaara            #+#    #+#              #
#    Updated: 2021/02/20 13:11:43 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L /Users/Vilicee/Coding/FdF/minilibx -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit

SOURCE_DIR = ./srcs/
SOURCE_LIST = main.c \
	ft_fdf.c \
	ft_save_string.c \
	ft_convert_to_i.c \
	ft_free_str.c \
	ft_create_int_arr.c \
	ft_free_line.c \
	ft_key_input.c \
	ft_color_set.c \
	ft_calc_color.c \
	ft_projection.c \
	ft_draw_horizontal.c \
	ft_draw_vertical.c \
	ft_color_check.c \
	ft_reset.c \
	ft_set_box_size.c \
	ft_clip.c \
	ft_move.c

SRCS = $(addprefix $(SOURCE_DIR), $(SOURCE_LIST))

OBJECTS = main.o \
	ft_fdf.o \
	ft_save_string.o \
	ft_convert_to_i.o \
	ft_free_line.o \
	ft_free_str.o \
	ft_create_int_arr.o \
	ft_key_input.o \
	ft_color_set.o \
	ft_calc_color.o \
	ft_projection.o \
	ft_draw_horizontal.o \
	ft_draw_vertical.o \
	ft_color_check.o \
	ft_reset.o \
	ft_set_box_size.o \
	ft_clip.o \
	ft_move.o

INCLUDES = Libft/includes

LIBRARY = Libft/libft.a

LIBDIR = Libft

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBDIR)
	gcc -c $(SRCS)
	gcc $(FLAGS) $(LIBRARY) $(OBJECTS) $(LIBFLAGS) -I $(INCLUDES) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(SRCS): $(HEADER)

clean:
	$(MAKE) clean -C $(LIBDIR)
	/bin/rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
