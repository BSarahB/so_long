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
			$(SRC_DIR)/get_map_and_images_id.c \
			$(SRC_DIR)/error_display.c \
			$(SRC_DIR)/destroy_and_update_image.c \
			$(SRC_DIR)/rescale.c \
			$(SRC_DIR)/push_assets_to_window.c \
			$(SRC_DIR)/utils2.c \

OBJS = $(SRCS:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I mlx

L_FLAGS		=	-L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11 

all:		$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	make -C mlx 
	$(CC) $(L_FLAGS) -o $@ $^ $(MLX_FLAGS) 

clean:
			make clean -C mlx
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean re all 