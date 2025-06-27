NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -g -Wunreachable-code -Ofast -fPIE
LIBMLX		= ./lib/MLX42
CC			= gcc

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBFT_DIR	= ./lib/libft_
PRINTF_DIR 	= ./lib/printf_
MLX_PATH	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT_PATH	= ./lib/libft/libft.a
PRINTF_PATH	= ./lib/printf/libftprintf.a
LIBS_PATH	= $(LIBFT_PATH) $(PRINTF_PATH) $(MLX_PATH)
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx