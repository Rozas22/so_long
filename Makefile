NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -g -Wunreachable-code -Ofast -fPIE
LIBMLX		= ./lib/MLX42
CC			= gcc

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBFT_DIR	= ./lib/libft
PRINTF_DIR 	= ./lib/printf
MLX_PATH	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT_PATH	= ./lib/libft/libft.a
PRINTF_PATH	= ./lib/printf/libftprintf.a
LIBS_PATH	= $(LIBFT_PATH) $(PRINTF_PATH) $(MLX_PATH)
SRCS		= ./src/so_long.c \	
							./src/main.c \
							./src/map_ceck.c \
							./src/map_read.c \
							./src/map_tools.c \
							./src/is_map_fully_accessible.c \
