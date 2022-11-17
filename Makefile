# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/14 11:29:48 by yitoh         #+#    #+#                  #
#    Updated: 2022/11/17 10:58:10 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_printf.c ft_printf_char.c ft_printf_hex.c
REGOBJ = $(SRC:.c=.o)
BONUSSRC = 
BONUSOBJ = $(BONUSSRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = libftprintf.a

ifdef WITH_BONUS
OBJ = $(REGOBJ) $(BONUSOBJ)
else
OBJ = $(REGOBJ)
endif

all: $(NAME) #$(LIBFT)

$(NAME): $(OBJ)
	@ar -crs $@ $^

%.o: %.c
	@$(CC) -c $(CFLAG) $< -o $@

# $(LIBFT):
# 	@$(MAKE) -C libft all

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
