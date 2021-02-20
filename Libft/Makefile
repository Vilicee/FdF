# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 18:25:08 by wvaara            #+#    #+#              #
#    Updated: 2021/02/18 12:42:12 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

SRCS = ft_putnbr.c ft_putchar.c ft_strlen.c ft_putnbr.c ft_putstr.c \
	ft_strcpy.c ft_memset.c ft_strdup.c ft_strncpy.c ft_memcpy.c \
	ft_strncat.c ft_memccpy.c ft_memmove.c ft_strcmp.c ft_memchr.c \
	ft_strstr.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_memcmp.c \
	ft_strchr.c ft_putendl.c ft_strrchr.c ft_strnstr.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_atoi.c ft_bzero.c ft_memalloc.c ft_memdel.c ft_strsplit.c \
	ft_strnew.c ft_strcat.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_wordcount.c ft_strrev.c \
	ft_wordlength.c ft_itoa.c ft_intlen.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstnew.c ft_lstmap.c ft_linecount.c ft_gnl.c

LIBRARY = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(LIBRARY)
	@ranlib $(NAME)

$(SRCS): $(INCLUDES)libft.h

clean:
	rm -f $(LIBRARY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.Phony: all clean fclean re
