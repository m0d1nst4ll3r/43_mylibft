# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2025/12/15 22:34:33 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES_LIBFT	= ft_strlen.c \
				  ft_strchr.c \
				  ft_strstr.c \
				  ft_strncmp.c \
				  ft_strcmp.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_strlcpy.c \
				  ft_strcpy.c \
				  ft_strcat.c \
				  ft_memset.c \
				  ft_memcpy.c \
				  ft_strupper.c \
				  ft_strlower.c \
				  ft_strrev.c \
				  ft_atoi.c \
				  ft_strdup.c \
				  ft_strndup.c \
				  ft_substr.c \
				  ft_strjoin.c \
				  ft_split.c \
				  ft_itoa.c \
				  ft_abs.c \
				  ft_min.c \
				  ft_max.c \
				  ft_write.c
CFILES_PRINTF	= ft_printf.c \
				  buffer.c \
				  flags.c \
				  convert.c \
				  convert_c.c \
				  convert_s.c \
				  convert_di.c \
				  convert_boux.c \
				  convert_p.c \
				  utils.c \
				  utils_print.c \
				  utils_print2.c
CFILES_GNL		= get_next_line.c \
				  get_next_line_utils.c

LIBFTDIR		= src/libft/
PRINTDIR		= src/printf/
GETNLDIR		= src/gnl/

SRC_LIBFT		= $(addprefix $(LIBFTDIR), $(CFILES_LIBFT))
SRC_PRINTF		= $(addprefix $(PRINTDIR), $(CFILES_PRINTF))
SRC_GNL			= $(addprefix $(GETNLDIR), $(CFILES_GNL))

SRC				= $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL)
OBJ				= $(SRC:.c=.o)
DEP				= $(SRC:.c=.d)

NAME			= libft.a

INC				= inc/

CC				= cc
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= $(addprefix -I,$(INC)) -MMD -MP
MAKEFLAGS		+= --no-print-directory -j

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $@ $^

%.o:		%.c
			$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
			rm -f $(OBJ) $(DEP)

fclean:
			rm -f $(NAME) $(OBJ) $(DEP)

re:
			$(MAKE) fclean
			$(MAKE) all

-include $(DEP)

.PHONY: clean fclean re
