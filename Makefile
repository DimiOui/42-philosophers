# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 12:23:41 by dimioui           #+#    #+#              #
#    Updated: 2022/02/10 12:36:34 by dimioui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(addprefix srcs/, \
							main.c \
				)

OBJS		= ${SRCS:.c=.o}

NAME		= philosophers

RM			= @rm -f

CC			= @cc

CFLAGS		= -pthread -Wall -Wextra -Werror -Iincludes -c

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcsv ${NAME} ${OBJS} > /dev/null

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: re clean fclean
