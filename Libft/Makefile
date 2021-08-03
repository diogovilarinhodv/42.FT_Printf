CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= run

LIB	= libft.a

AR	= ar rc

RM	= rm -f

SRCS	= ft_strlen.c ft_itoa.c ft_strdup.c ft_strjoin.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${AR} ${LIB} ${OBJS}

all:	$(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${LIB}
	
re:	fclean all


.PHONY:	all clean fclean re
