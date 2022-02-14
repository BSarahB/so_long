NAME = so_long
CC = clang

INCLUDE_DIR	=	.
SRC_DIR	=	src
SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/update_free_memory.c \
			$(SRC_DIR)/ft_split.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/check_error_file.c \
			$(SRC_DIR)/check_map_valid.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/move.c \
			$(SRC_DIR)/get_map.c \
			$(SRC_DIR)/error_display.c \
					
OBJS = $(SRCS:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I mlx

L_FLAGS		=	-L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11 

all:		$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) #clang -Wall -Wextra -Werror -I . -I mlx -03 -c main.c -o main.o$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	make -C mlx #libmlx.a cree
	$(CC) $(L_FLAGS) -o $@ $^ $(MLX_FLAGS) #clang -L mlx -o so_long main.o -lm -lmlx -lXext -lX11


clean:
			make clean -C mlx
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean re all 