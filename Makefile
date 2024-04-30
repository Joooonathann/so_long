#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      MLX42/build/CMakeFiles/3.22.1/CompilerIdC/CMakeCCompilerId.c \
                          MLX42/build/CMakeFiles/3.22.1/CompilerIdCXX/CMakeCXXCompilerId.cpp \
                          MLX42/build/mlx_frag_shader.c \
                          MLX42/build/mlx_vert_shader.c \
                          MLX42/lib/glad/glad.c \
                          MLX42/lib/png/lodepng.c \
                          MLX42/src/font/mlx_font.c \
                          MLX42/src/mlx_cursor.c \
                          MLX42/src/mlx_exit.c \
                          MLX42/src/mlx_images.c \
                          MLX42/src/mlx_init.c \
                          MLX42/src/mlx_keys.c \
                          MLX42/src/mlx_loop.c \
                          MLX42/src/mlx_monitor.c \
                          MLX42/src/mlx_mouse.c \
                          MLX42/src/mlx_put_pixel.c \
                          MLX42/src/mlx_window.c \
                          MLX42/src/textures/mlx_png.c \
                          MLX42/src/textures/mlx_texture.c \
                          MLX42/src/textures/mlx_xpm42.c \
                          MLX42/src/utils/mlx_compare.c \
                          MLX42/src/utils/mlx_error.c \
                          MLX42/src/utils/mlx_list.c \
                          MLX42/src/utils/mlx_utils.c \
                          MLX42/tests/tests.cpp \
                          src/basic/ft_strcmp.c \
                          src/basic/ft_strlen.c \
                          src/map/parsing/destroy_map.c \
                          src/map/parsing/errors_controller.c \
                          src/map/parsing/flood_fill_map.c \
                          src/map/parsing/get_array_map.c \
                          src/map/parsing/get_size_map.c \
                          src/map/parsing/initialize_map.c \
                          src/map/parsing/is_valid_object_map.c \
                          src/map/parsing/is_valid_path.c \
                          src/map/parsing/set_malloc_map.c \
                          src/map/parsing/set_object_map.c \
                          src/map/parsing/wall_surround_map.c \
                          src/so_long.c \
                          printf/src/createnode.c \
                          printf/src/ft_convert.c \
                          printf/src/ft_convert_ptr.c \
                          printf/src/ft_flags.c \
                          printf/src/ft_freestock.c \
                          printf/src/ft_printchar.c \
                          printf/src/ft_printf.c \
                          printf/src/ft_printlist.c \
                          printf/src/ft_pushint.c \
                          printf/src/ft_pushintunsigned.c \
                          printf/src/ft_pushstr.c \
                          printf/src/ft_stock.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      MLX42/build/CMakeFiles/3.22.1/CompilerIdC/CMakeCCompilerId.c \
                          MLX42/build/CMakeFiles/3.22.1/CompilerIdCXX/CMakeCXXCompilerId.cpp \
                          MLX42/build/mlx_frag_shader.c \
                          MLX42/build/mlx_vert_shader.c \
                          MLX42/lib/glad/glad.c \
                          MLX42/lib/png/lodepng.c \
                          MLX42/src/font/mlx_font.c \
                          MLX42/src/mlx_cursor.c \
                          MLX42/src/mlx_exit.c \
                          MLX42/src/mlx_images.c \
                          MLX42/src/mlx_init.c \
                          MLX42/src/mlx_keys.c \
                          MLX42/src/mlx_loop.c \
                          MLX42/src/mlx_monitor.c \
                          MLX42/src/mlx_mouse.c \
                          MLX42/src/mlx_put_pixel.c \
                          MLX42/src/mlx_window.c \
                          MLX42/src/textures/mlx_png.c \
                          MLX42/src/textures/mlx_texture.c \
                          MLX42/src/textures/mlx_xpm42.c \
                          MLX42/src/utils/mlx_compare.c \
                          MLX42/src/utils/mlx_error.c \
                          MLX42/src/utils/mlx_list.c \
                          MLX42/src/utils/mlx_utils.c \
                          MLX42/tests/tests.cpp \
                          src/basic/ft_strcmp.c \
                          src/basic/ft_strlen.c \
                          src/map/parsing/destroy_map.c \
                          src/map/parsing/errors_controller.c \
                          src/map/parsing/flood_fill_map.c \
                          src/map/parsing/get_array_map.c \
                          src/map/parsing/get_size_map.c \
                          src/map/parsing/initialize_map.c \
                          src/map/parsing/is_valid_object_map.c \
                          src/map/parsing/is_valid_path.c \
                          src/map/parsing/set_malloc_map.c \
                          src/map/parsing/set_object_map.c \
                          src/map/parsing/wall_surround_map.c \
                          src/so_long.c \
                          printf/src/createnode.c \
                          printf/src/ft_convert.c \
                          printf/src/ft_convert_ptr.c \
                          printf/src/ft_flags.c \
                          printf/src/ft_freestock.c \
                          printf/src/ft_printchar.c \
                          printf/src/ft_printf.c \
                          printf/src/ft_printlist.c \
                          printf/src/ft_pushint.c \
                          printf/src/ft_pushintunsigned.c \
                          printf/src/ft_pushstr.c \
                          printf/src/ft_stock.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
