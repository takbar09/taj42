# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: takbar <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/22 14:12:19 by takbar        #+#    #+#                  #
#    Updated: 2023/05/14 18:36:01 by takbar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRCF = ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_unsigned_nbr.c ft_print_hex_nbr.c ft_print_voidptr_hex.c
OBJF = $(SRCF:.c=.o)

all:$(NAME)

$(NAME): $(OBJF)
	ar -rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
