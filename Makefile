PUSH_FILES = push_swap.c check.c push.c swap.c rotate.c rev_rotate.c \
			create_stack.c sort.c cost_and_target.c moves_utils.c nodes_utils.c \

OBJS = ${PUSH_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
LIBFTA = ./libft/libft.a
LIBFTD = ./libft

BONUS = ./bonus_checker/checker.c ./bonus_checker/get_next_line.c ./bonus_checker/get_next_line_utils.c
OBJSB = ${BONUS:.c=.o}
CHECKER = checker

all:		${NAME}

${NAME}:	${OBJS} ${LIBFTA}
			${CC} ${CFLAGS} main.c $(OBJS) ${LIBFTA} -o ${NAME}

${LIBFTA}:	${LIBFTD}
		make -C ${LIBFTD}

bonus: ${CHECKER} 

${CHECKER}:		${OBJSB}
				${CC} ${CFLAGS} ${OBJS} ${OBJSB} ${LIBFTA} -o ${CHECKER}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
