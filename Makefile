
NAME = so_long

CC = cc
CFLAGS = -I inc/ -Wall -Werror -Wextra 

LIBFT_PATH = libft/
MLX_PATH = minilibx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lminilibx -lmlx -lX11 -lXext -lXrender -lbsd -lm 
LIBFT_LIB = $(LIBFT_PATH)libft.a


CFILES = \
		src/main.c\
		src/error.c\
		src/mapping.c\
		src/angie.c\
		src/createmap.c\
		src/playing.c\


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
	norminette libft/ src/ inc/

.PHONY: all clean fclean re norm
