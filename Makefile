NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -g -Wunreachable-code -Ofast -fPIE
LIBMLX		= ./lib/MLX42
CC			= gcc

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBFT_DIR	= ./lib/libft_
PRINTF_DIR 	= ./lib/printf_
LIBFT_PATH	= ./lib/libft_/libft.a
PRINTF_PATH	= ./lib/printf_/libftprintf.a
MLX_PATH	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS_PATH	= $(LIBFT_PATH) $(PRINTF_PATH) $(MLX_PATH)
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

libft_:
	@make -C $(LIBFT_DIR)

printf_:
	@make -C $(PRINTF_DIR)

all: libft_ printf_ libmlx $(NAME)



libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) || exit 1

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS_PATH) $(HEADERS) -o $(NAME)


clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx libft_ printf_
