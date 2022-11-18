# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/14 11:29:48 by yitoh         #+#    #+#                  #
#    Updated: 2022/11/18 17:39:03 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_printf_char.c ft_printf_hex.c #ft_printf.c 
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@ar -crs $@ $(OBJ) $(LIBFT)

%.o: %.c
	@$(CC) -c $(CFLAG) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all clean

#$(BUILDDIR):
#	@mkdir $(BUILDDIR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME) a.out
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all bonus test

test: $(NAME)
	@$(CC) $(CFLAG) *.c libft/ft_strlen.c -o ./a.out
