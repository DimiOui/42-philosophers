# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 12:23:41 by dimioui           #+#    #+#              #
#    Updated: 2022/02/15 15:46:50 by dimioui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define compiling
	@printf '$(shell tput setaf 69)Compiling$(shell tput sgr0) %s\n' $1
	@$(CC) $(CFLAGS) -c $1 -o $2
endef

define removing
	@printf '$(shell tput setaf 59)Removing$(shell tput sgr0) %s\n' $1
	@$(RM) $1 > /dev/null
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
			@printf '$(shell tput setaf 29)Finished √ %s\n$(shell tput sgr0)' $1
			@printf '$(shell tput setaf 69)Linking objs...\n$(shell tput sgr0)'
			$(CC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)
			@printf '$(shell tput setaf 29)Finished √ %s\n$(shell tput sgr0)' $1
			@make -s norminette

norminette:
			@if norminette $(SRCS) >/dev/null; then\
				echo "$(shell tput setaf 35)Norminette check √$(shell tput sgr0)";\
			else\
				echo "$(shell tput setaf 1)Norminette check ✕$(shell tput sgr0)";\
			fi

all:		$(NAME)

clean:
			$(call removing,$(OBJS))

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re clean fclean
