CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= run

LIB	= libftprintf.a

AR	= ar rc

RM	= rm -f

SRCS	= ft_printf.c ft_unsigned_itoa.c

LIBFT_FUNCS	= Libft/ft_itoa.c Libft/ft_strlen.c Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_atoi.c
		
FORMATS	= formats/c_format.c formats/d_format.c formats/p_format.c formats/s_format.c formats/u_format.c \
		formats/x_format.c formats/xbig_format.c formats/percentage_format.c

CONVERTS = converts/p_dec_to_hexa.c converts/x_dec_to_hexa.c converts/xbig_dec_to_hexa.c

UTILS = utils/check_format.c utils/count_flag.c utils/reset_count_flag.c utils/format_finder.c utils/ff_writer.c

FLAGS_HANDLERS = flags_handler/less_with_width.c flags_handler/precision_handler.c flags_handler/precision_padding.c \
					flags_handler/precision_string_handler.c flags_handler/space_or_plus.c flags_handler/width_handler.c \
					flags_handler/width_padding.c

BONUS = ${SRCS}

OBJS	= ${SRCS:.c=.o} ${FORMATS:.c=.o} ${CONVERTS:.c=.o} ${UTILS:.c=.o} ${LIBFT_FUNCS:.c=.o} ${FLAGS_HANDLERS:.c=.o}

OBJS_B	= ${BONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${AR} ${LIB} ${OBJS}

bonus: ${OBJS} ${OBJS_B}
	${AR} ${LIB} ${OBJS} ${OBJS_B}

all:	$(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${LIB}
	
re:	fclean all

rebonus: re bonus

.PHONY:	all bonus rebonus clean fclean re
