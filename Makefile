# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 12:23:41 by dimioui           #+#    #+#              #
#    Updated: 2022/02/14 15:27:04 by dimioui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(addprefix srcs/, \
							main.c \
							error.c \
							parsing.c \
							utils.c \
							philo_actions.c \
				)

OBJS		= ${SRCS:.c=.o}

NAME		= philo

RM			= @rm -f

CC			= @cc

CFLAGS		= -Wall -Wextra -Werror -Iincludes -c -g

INCLUDE		= -pthread

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	$(OBJS)
			$(CC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re clean fclean
