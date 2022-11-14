# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/14 11:29:48 by yitoh         #+#    #+#                  #
#    Updated: 2022/11/14 12:06:25 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_printf_char.c 
REGOBJ = $(SRC:.c=.o)
BONUSSRC = ft_
BONUSOBJ = $(BONUSSRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = libftprintf.a
LIBFT = libft.a

ifdef WITH_BONUS
OBJ = $(REGOBJ) $(BONUSOBJ)
else
OBJ = $(REGOBJ)
endif

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ)
	@ar -crs $@ $^

%.o: %.c
	@$(CC) -c $(CFLAG) $< -o $@

$(LIBFT):
	@$(MAKE) -C libft all

#$(BUILDDIR):
#	@mkdir $(BUILDDIR)

clean:
	@rm -rf $(REGOBJ) $(BONUSOBJ)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

bonus: 
	@$(MAKE) WITH_BONUS=1 all

.PHONY: clean fclean all bonus test

test: $(NAME) $(LIBFT)
	@$(CC) $(CFLAG) *.c -o ./a.out
