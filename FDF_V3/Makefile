# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takbar <takbar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:12:19 by takbar            #+#    #+#              #
#    Updated: 2023/09/09 18:00:24 by takbar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft.a
PRINTF = libftprintf.a
MLX42 = libmlx42.a

SRCF = fdf.c fdf_util.c read.c draw.c projection.c   

OBJF = $(SRCF:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAG = -lglfw -L "/Users/takbar/.brew/opt/glfw/lib/"
INCLUDE = -I include

all: $(NAME)

$(NAME) : $(OBJF)
	@make -C libft
	@make -C libft/ft_printf
	@make -C MLX42/build
	$(CC) $(CFLAGS) $(OBJF) $(INCLUDE) libft/$(LIBFT) libft/ft_printf/$(PRINTF) MLX42/build/$(MLX42) $(MLX_FLAG) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@make clean -C MLX42/build
	rm -f $(OBJF)

fclean: clean
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	@make fclean -C MLX42/build
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
