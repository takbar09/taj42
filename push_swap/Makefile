# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: takbar <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/22 14:12:19 by takbar        #+#    #+#                  #
#    Updated: 2023/06/25 18:58:56 by takbar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
PRINTF = libftprintf.a

SRCF = check_args.c commands.c init_stack.c push_swap.c stack.c simple_sort.c

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
