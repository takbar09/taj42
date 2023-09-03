# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: takbar <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/22 14:12:19 by takbar        #+#    #+#                  #
#    Updated: 2023/08/05 17:46:40 by takbar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft.a
PRINTF = libftprintf.a

SRCF = fdf.c read.c 

OBJF = $(SRCF:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include

all: $(NAME)

$(NAME) : $(OBJF)
	@make -C libft
	@make -C libft/ft_printf
	$(CC) $(CFLAGS) $(OBJF) $(INCLUDE) libft/$(LIBFT) libft/ft_printf/$(PRINTF) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	rm -f $(OBJF)

fclean: clean
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
