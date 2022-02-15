# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 12:23:41 by dimioui           #+#    #+#              #
#    Updated: 2022/02/15 14:38:53 by dimioui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define compiling
	@printf 'Compiling %s\n' $1
	@$(CC) $(CFLAGS) -c $1 -o $2
endef

define removing
	@printf ' %s\n' $1
	@$(RM) $1 > /dev/null
endef

define norminette

endef


SRCS		=	$(addprefix srcs/, \
							main.c \
							error.c \
							parsing.c \
							utils.c \
							philo_actions.c \
				)

OBJS		= $(SRCS:.c=.o)

NAME		= philo

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -c -Iincludes -g

INCLUDE		= -pthread

%.o : %.c
			$(call compiling,$<,$(<:.c=.o),0)

${NAME}:	$(OBJS)
			$(CC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)
			@printf 'Finished %s\n' $1
			@make -s norminette

norminette:
			@if norminette $(SRCS) >/dev/null; then\
				echo "$(shell tput bold)$(shell tput setaf 6)Norminette check : [OK]$(shell tput sgr0)";\
			else\
				echo "$(shell tput bold)$(shell tput setaf 1)Norminette check : [KO]$(shell tput sgr0)";\
			fi

all:		$(NAME)

clean:
			$(call removing,$(OBJS))

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re clean fclean
