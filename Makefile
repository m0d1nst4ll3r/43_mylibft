# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2026/01/19 15:30:04 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
CFILES_LIBFT	= ft_isspace.c \
				  ft_isdigit.c \
				  ft_ishexa.c \
				  ft_strlen.c \
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
				  ft_write.c \
				  ft_atoi_strict.c \
				  ft_atos.c \
				  ft_atoh.c \
				  ft_select_sort.c \
				  ft_free.c
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

SRC				= $(addprefix $(LIBFTDIR), $(CFILES_LIBFT)) \
				  $(addprefix $(PRINTDIR), $(CFILES_PRINTF)) \
				  $(addprefix $(GETNLDIR), $(CFILES_GNL))

# Build directory
BUILDDIR		= .build

# Object and dependency files
OBJ				= $(SRC:%.c=$(BUILDDIR)/%.o)
DEP				= $(OBJ:.o=.d)

# Output binary
NAME			= libft.a

# Header directories
INC				= inc

# Compiler settings
CC				= cc
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= $(addprefix -I,$(INC)) -MMD -MP
MAKEFLAGS		+= --no-print-directory
MAKEFLAGS		:= $(MAKEFLAGS) $(if $(filter -j%,$(MAKEFLAGS)),,-j)

# Default rule
all:		$(NAME)

# Create archive from objects
$(NAME):	$(OBJ)
			$(AR) $@ $^

# Compile source -> object (auto-create directories)
$(BUILDDIR)/%.o:		%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# Cleanup
clean:
			rm -rf $(BUILDDIR)

fclean:
			rm -rf $(NAME) $(BUILDDIR)

re:
			$(MAKE) fclean
			$(MAKE) all

# Include dependency files
-include $(DEP)

.PHONY: clean fclean re
