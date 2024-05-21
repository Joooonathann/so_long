NAME		= 	so_long
CC			= 	cc
CFLAGS		= 	-Wextra -Wall -Werror -I ./include
INC			= 	-Iinclude -ldl -lglfw -pthread -lm
LIBMLX		= 	MLX42/build/libmlx42.a
PRINTF		= 	printf/libftprintf.a
MAKE_PRINTF	= 	@make -C printf

SRC			= 	./src/basic/ft_strcmp.c\
				./src/basic/ft_strlen.c\
				./src/basic/swap_chars.c\
				./src/game/hooks/hook.c\
				./src/game/errors_controller_game.c\
				./src/game/hooks/hook_mov.c\
				./src/game/player/movements.c\
				./src/game/player/pos.c\
				./src/game/player/react_player.c\
				./src/game/player/spawn_player.c\
				./src/game/delete_all_images.c\
				./src/game/resize_game.c\
				./src/map/init/draw_map.c\
				./src/map/init/init_game.c\
				./src/map/parsing/destroy_map.c\
				./src/map/parsing/errors_controller.c\
				./src/map/parsing/flood_fill_map.c\
				./src/map/parsing/get_array_map.c\
				./src/map/parsing/get_size_map.c\
				./src/map/parsing/initialize_map.c\
				./src/map/parsing/is_valid_object_map.c\
				./src/map/parsing/is_valid_path.c\
				./src/map/parsing/set_malloc_map.c\
				./src/map/parsing/set_object_map.c\
				./src/map/parsing/wall_surround_map.c\
				./src/so_long.c

OBJ	= ${SRC:.c=.o}

all: $(NAME)

$(PRINTF):
	$(MAKE_PRINTF)

$(LIBMLX):
	@cmake -S MLX42 -B MLX42/build && make -C MLX42/build -j4
	
$(NAME): $(OBJ) $(PRINTF) $(LIBMLX)
	$(CC) $(OBJ) $(PRINTF) $(LIBMLX) $(INC) -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE_PRINTF) clean
	rm -rf MLX42/build

fclean: clean
	rm -rf $(NAME)
	$(MAKE_PRINTF) fclean

re: fclean all
	$(MAKE_PRINTF) re

.PHONY: all clean fclean re
