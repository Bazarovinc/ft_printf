# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 14:45:43 by ctelma            #+#    #+#              #
#    Updated: 2020/01/03 19:11:25 by ctelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS_DIRECTORY)

# LIBFT

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/

# LIBFT_HEADERS

LIBFT_HEADERS_LIST = \
	libft.h
LIBFT_HEADERS_DIRECTORY = $(LIBFT_DIRECTORY)includes/
LIBFT_HEADERS = $(addprefix $(LIBFT_HEADERS_DIRECTORY), $(LIBFT_HEADERS_LIST))

# LIBFT_SOURCES

LIBFT_SOURCES_DIRECTORY = $(LIBFT_DIRECTORY)
LIBFT_SOURCES_LIST =\
	        ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	        ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	        ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	        ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	        ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	        ft_isprint.c ft_toupper.c ft_tolower.c \
	        ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	        ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	        ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	        ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	        ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	        ft_lstmap.c \
	        ft_islower.c ft_isupper.c ft_iswhitespace.c ft_swap.c ft_sqrt.c \
	        ft_recursive_factorial.c ft_issymb.c

LIBFT_SOURCES = $(addprefix $(LIBFT_SOURCES_DIRECTORY), $(LIBFT_SOURCES_LIST))

# LIBFT_OBJECTS

LIBFT_OBJECTS_DIRECTORY = $(LIBFT_DIRECTORY)
LIBFT_OBJECTS_LIST = $(patsubst %.c, %.o, $(LIBFT_SOURCES_LIST))
LIBFT_OBJECTS = $(addprefix $(LIBFT_OBJECTS_DIRECTORY), $(LIBFT_OBJECTS_LIST))

# HEADERS

HEADERS_LIST = ft_printf.h

HEADERS_DIRECTORY = ./header/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# SOURCES

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = \
	base.c check_flags.c f.c ft_itoa_u.c hash.c \
	length.c p.c print_base.c rounding.c \
	space_back.c validation.c c.c check_mem.c \
	ft_itoa_base.c ft_print.c initialization.c make_prec.c \
	pre_print.c print_cs.c print_p.c s.c space_forward.c \
	types.c width.c cast_len.c di.c ft_itoa_l.c \
	ft_printf.c len_5_l.c one_space_forward.c precision.c \
	print_diuf.c print_symb.c size_str.c str_w.c u.c check_point_f.c \
	check_inf.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFT_OBJECTS) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
