NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror
LIBMLX		= ./lib/MLX42
CC			= cc

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBFT_DIR	= ./lib/libft_
PRINTF_DIR 	= ./lib/printf_
LIBFT_PATH	= ./lib/libft_/libft.a
PRINTF_PATH	= ./lib/printf_/libftprintf.a
MLX_PATH	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS_PATH	= $(LIBFT_PATH) $(PRINTF_PATH) $(MLX_PATH)

SRCS 		= 	src/main.c 				\
				src/errors.c 			\
				src/init_window.c 		\
				src/is_map_fully_accessible.c \
				src/map_check.c 		\
				src/map_read.c 			\
				src/map_textures.c 		\
				src/map_tools.c 		\
				src/player_movements.c 	\
				src/player_tools.c


OBJS 		= ${SRCS:.c=.o}


all: mlx libft_ printf_ $(NAME)

libft_:
	@make -C $(LIBFT_DIR)

printf_:
	@make -C $(PRINTF_DIR)


mlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/42-Fundacion-Telefonica/MLX42.git $(LIBMLX); \
		echo "MLX42 not found. Downloading..."; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) || exit 1

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS_PATH) $(HEADERS) -o $(NAME)


clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME) $(LIBMLX)

re: clean all

.PHONY: all clean fclean re mlx libft_ printf_
