# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2025/12/02 12:25:42 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror -Iinc

LIBFTDIR	= src/libft/
PRINTFDIR	= src/printf/
GNLDIR		= src/gnl/
LIBMLCDIR	= src/libmlc/
SRC_LIBFT	= $(addprefix $(LIBFTDIR), \
			  ft_strlen.c ft_strchr.c ft_strstr.c ft_strncmp.c ft_strcmp.c \
			  ft_memchr.c ft_memcmp.c \
			  ft_strlcpy.c ft_strcpy.c ft_strcat.c ft_memset.c ft_memcpy.c \
			  ft_strupper.c ft_strlower.c ft_strrev.c \
			  ft_atoi.c ft_strdup.c ft_strndup.c \
			  ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
			  ft_abs.c ft_min.c ft_max.c)
SRC_PRINTF	= $(addprefix $(PRINTFDIR), \
			  ft_printf.c buffer.c flags.c \
			  convert.c convert_c.c convert_s.c convert_di.c convert_boux.c convert_p.c \
			  utils.c utils_print.c utils_print2.c)
SRC_GNL		= $(addprefix $(GNLDIR), \
			  get_next_line.c get_next_line_utils.c)
SRC_MLC		= $(addprefix $(LIBMLCDIR), \
			  libmalloc_free_all.c libmalloc_malloc.c libmalloc_free.c)
SRC			= $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL) $(SRC_MLC)

OBJ		= $(SRC:.c=.o)

NAME	= libft.a

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $@ $^

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: clean fclean all
