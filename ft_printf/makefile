SRC	= $(wildcard srcs/*.c)
OBJS 	= ${SRC:.c=.o}
INCS	= include
NAME	= libftprintf.a
LIBC	= ar rc
LIBR	= ranlib
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re 
