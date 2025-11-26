NAME = solong.a

SOURCE = 	mapstuff.c \
		count_stuff.c \
		borders.c \
		main.c

HEADER = so_long.h

CFLAGS += -Wall -Wextra -Werror -g 

MINIFLAGS += -lmlx -lX11 -lXext -lm

OBJECTS = $(SOURCE:.c=.o)

LIBFT = libft/libft.a

CC = cc

RM = rm -f

CREATION = ar rcs


.c.o:
	${CC} ${CFLAGS} ${MINIFLAGS} -c $< -o ${<:.c=.o} ${LIBFT}

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
