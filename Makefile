NAME = solong

SOURCE = 	check_and_find.c \
			check_path.c \
			game.c \
			gamehook.c \
			input_and_all.c \
			mapstuff.c \
			moves.c \
			so_long.c

HEADER = so_long.h

CFLAGS += -Wall -Wextra -Werror -g 

MINIFLAGS += -lmlx -lX11 -lXext -lm

OBJECTS = $(SOURCE:.c=.o)

LIBFT = libft/libft.a

CC = cc

RM = rm -f

CREATION = ar rcs


%.o: %.c
	${CC} ${CFLAGS} $ -c $< -o $@
${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} ${MINIFLAGS} ${OBJECTS} ${LIBFT} -o ${NAME}
clean:	
	${RM} ${OBJECTS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
all:	${NAME}
make:	make all
aout:
	cc *c libft/libft.a -g -lmlx -lX11 -lXext -lm -Wall -Wextra -Werror


.PHONY: clean fclean re all
