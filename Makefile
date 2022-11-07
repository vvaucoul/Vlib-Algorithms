# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 22:18:48 by vvaucoul          #+#    #+#              #
#    Updated: 2022/11/07 15:43:59 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_GREEN = \033[1;92m
COLOR_RED = \033[1;91m
COLOR_YELLOW = \033[1;93m
COLOR_BLUE = \033[1;94m
COLOR_MAGENTA = \033[1;95m
COLOR_CYAN = \033[1;96m
COLOR_WHITE = \033[1;97m


CC			=	gcc
INCLUDES	=	-I ./includes
CFLAGS		=	$(INCLUDES) -Wall -Wextra -g3 -Wincompatible-pointer-types #-Werror 
NAME		=	lib-algorithms.a

SRCS_DIR	=	./srcs/
SRCS    	=	$(shell find $(SRCS_DIR) -name "*.c")
OBJS		=	$(SRCS:.c=.o)
DEPENDS		=	$(SRCS:.c=.d)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(COLOR_GREEN)$(NAME)$(COLOR_RESET) $(COLOR_WHITE): $(COLOR_YELLOW)$<$(COLOR_RESET) $(COLOR_WHITE)-> $(COLOR_YELLOW)$@$(COLOR_RESET)\n"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(COLOR_GREEN)[OK]$(COLOR_RESET)\n" $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(DEPENDS)

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

test: all
	@$(CC) $(CFLAGS) -o test tests/main.c $(NAME)
	@printf "$(COLOR_GREEN)[OK]$(COLOR_RESET)\n" $(NAME)

check-install:
	@gcc -Wall -Wextra -Werror -g3 tests/check-install.c -l -algorithms -o checker
	@./checker
	@rm -f checker && make -s -C . fclean

install: $(NAME)
	@cp $(NAME) /usr/local/lib/$(NAME)
	@printf "$(COLOR_WHITE)Installing: $(COLOR_GREEN)%s $(COLOR_END)\n" /usr/local/lib/$(NAME)
	@mkdir -p /usr/local/include/vlib
	@cp -r includes/* /usr/local/include/vlib
	@printf "$(COLOR_WHITE)Installing: $(COLOR_GREEN)%s $(COLOR_END)\n" /usr/local/include/vlib
	@make -s -C . check-install

uninstall:
	@rm -f /usr/local/lib/$(NAME)
	@rm -rf /usr/local/include/vlib/algorithms.h
	@rm -rf /usr/local/include/vlib/algorithms
	@printf "$(COLOR_WHITE)Uninstalling: $(COLOR_GREEN)%s $(COLOR_END)\n" /usr/local/lib/$(NAME)
	@printf "$(COLOR_WHITE)Uninstalling: $(COLOR_GREEN)%s $(COLOR_END)\n" /usr/local/include/vlib

.PHONY: all clean fclean re test check-install install uninstall

-include $(DEPENDS)