# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 17:49:44 by myang             #+#    #+#              #
#    Updated: 2017/09/28 19:06:32 by myang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLS_D = includes
OBJS_D = objs
SRCS_D = srcs
LIBFT_D = libft
MLX_D = minilibx_macos
FLAGS = -g -Wall -Wextra -Werror
INCLS = -I includes/
LIBFT = -L $(LIBFT_D) -lft
MLX = -L $(MLX_D) -lmlx -framework OpenGL -framework Appkit
CC = gcc $(FLAGS) $(INCLS)

SRCS_F = init\
		 main\
		 draw_window\
		 error_file\
		 landmarks\
		 key_input\
		 mouse_input

OBJS = $(SRCS_F:%=$(OBJS_D)/%.o)
SRCS = $(SRCS_F:%=$(SRCS_D)/%.c)

all : $(NAME)

$(OBJS_D):
	@mkdir -p $@
	@echo "\\0033[32m OBJS CREATED :\\0033[0m$@"

$(OBJS_D)/%.o: $(SRCS_D)/%.c
	@$(CC) -c $< -o $@

$(NAME) : $(OBJS_D) $(SRCS)
	@$(MAKE) -j -s $(OBJS)
	@echo "\\0033[32mMake recalls itself\\0033[0m"
	@make -j -s -C $(LIBFT_D)
	@make -j -s -C $(MLX_D)
	@$(CC) $(LIBFT) $(OBJS) $(MLX) -o $@
	@echo "\\0033[32m< $(NAME) > CREATED\\0033[0m"

clean :
	@rm -rf $(OBJS_D)
	@make clean -C $(LIBFT_D)
	@echo "\\0033[33mOBJS OF < $(NAME) > ARE DELETED\\0033[0m"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_D)
	@echo "\\0033[33m< $(NAME) > IS DELETED\\0033[0m"

re : fclean all

.PHONY : all clean fclean re
