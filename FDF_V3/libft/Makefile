# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: takbar <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/04 16:46:02 by takbar        #+#    #+#                  #
#    Updated: 2023/08/05 17:18:20 by takbar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Werror -Wextra
SRCF=ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_split.c ft_itoa.c ft_substr.c ft_strtrim.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c	
OBJF=$(SRCF:.c=.o)

all: libft.a

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
