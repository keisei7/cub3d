NAME = cub3d
INCDIR = include/
SRC = main.c \
		get_map.c \
		get_player.c \
		event.c \
		move.c \
		init_mlx.c \
		game.c \
		draw.c \
		error.c \
		arg.c \
		xmalloc.c \
		mlx_utils.c \
		libft/get_next_line.c \
		libft/get_next_line_utils.c
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
CFLAGS += -fsanitize=address

.c.o:
	${CC} ${CFLAGS} -Imlx -o $@ -c $< -I ${INCDIR}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} $(OBJ) -L /usr/X11R6/lib -lmlx -lXext -lX11 -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

simple: ${NAME}
	rm -rf ${OBJ}
	./cub3d maps/simple.cub

min: ${NAME}
	rm -rf ${OBJ}
	./cub3d maps/minimalist.cub

.PHONY: all clean fclean re
