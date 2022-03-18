# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:16:31 by thpham-v          #+#    #+#              #
#    Updated: 2022/03/18 04:53:10 by thpham-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d
MLX_DIR			=	./minilibx-linux/
SRC_DIR			=	./srcs/
INC_DIR			=	./inc/cub3d.h
LIBFT			=	./libft/
SRCS			=	main.c			\
					parsing_map.c
					
SRC_BASENAME	=	$(addprefix $(SRC_DIR), $(SRCS))		
OBJS			=	$(SRC_BASENAME:.c=.o)
CC				=	clang 
FLAGS			=	-Wall -Wextra -fsanitize=address -I $(MLX_DIR) -I $(INC_DIR) -I ./inc/ -I $(LIBFT) #-Werror

.c.o		:
				$(CC) $(FLAGS) -Imlx -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(INC_DIR)
			@make -C $(LIBFT)
			@make -C $(MLX_DIR)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
			@echo [$(NAME)] : Created !

clean		:
			@rm -rf $(OBJS)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX_DIR)
			@echo "[OBJS] Deleted"

fclean		:	clean
			@rm -f $(NAME)
			@make clean -C $(LIBFT)
			@echo "[$(NAME)]: Deleted"

re			:	fclean all

.PHONY: 		clean fclean all re