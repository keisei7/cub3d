
NAME		= cub3d
#CC			= clang
CC			= cc
CFLAGS		= -O3 -Wall -Wextra -Werror -I.
#CFLAGS		= -O3 -I.#os update...
#CFLAGS += -g
#CFLAGS += -fsanitize=address
MLX			= libmlx.dylib
MLXFLAG		= -framework OpenGL -framework AppKit
MINILIB     = minilibx_mms_20200219
#CFLAGS		= -Wall -Wextra -Werror -I./minilib_mms_20200219

INCDIR = include/


SRCS = main.c \
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

OBJS 	= $(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -o $@ -c $< -I ${INCDIR} -I $(MINILIB)

$(MLX) :
	cd 	"$(PWD)/$(MINILIB)" && make
	cd 	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(OBJS) $(MLX) $(MLXFLAG) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(MINILIB) clean
	rm -rf $(NAME)

re: fclean all

j: all
	./cub3d maps/simple.cub

min: all
	./cub3d maps/minimalist.cub

kill_mlx:
	rm -rf $(MLX)
	cd 	"$(PWD)/$(MINILIB)" && rm -f $(MLX)

.PHONY: all clean fclean re kill_mlx
