
NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = libft/
MLX_PATH = minilibx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lminilibx -lmlx -lX11 -lXext -lXrender -lbsd -lm -g
LIBFT_LIB = $(LIBFT_PATH)libft.a


CFILES = \
		main.c\
		error.c\
		mapping.c\
		angie.c\
		createmap.c\
		playing.c\


OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

subsystems:
	@make -C $(LIBFT_PATH) all
	@make -C $(MLX_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(LIBFT_LIB) $(MLX_LIB)  -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette libft initializer.c key_hook.c map.c move.c validate_input.c place_images.c main.c so_long.h victory.c helpers.c

.PHONY: all clean fclean re norm
