# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: takbar <takbar@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/05 20:24:33 by takbar        #+#    #+#                  #
#    Updated: 2022/11/06 13:39:37 by takbar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCF=ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_atoi.c
OBJF=$(SRCF:.c=.o)

all: libft.a

$(NAME): $(OBJF)
	ar -rc $(NAME) $^

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
