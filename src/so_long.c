#include "so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct objects
{
    int x;
    int y;
    struct objects *next;
} t_object;



static int  create_map()
{
	
}

mlx_image_t* img;
t_object *wall;

int colision_check(int new_x, int new_y)
{
    int wall_x = 300;
    int wall_y = 300;
    int wall_width = 100;
    int wall_height = 100;

    if ((new_x + img->width <= wall_x ||
          new_x >= wall_x + wall_width ||
          new_y + img->height <= wall_y ||
          new_y >= wall_y + wall_height))
    {
        img->instances[0].x = new_x;
        img->instances[0].y = new_y;
        return (1);
    }
    return (0);
}

void hook(void* param)
{
    mlx_t* mlx;
    mlx = param;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);

    int new_x = img->instances[0].x;
    int new_y = img->instances[0].y;

    if (mlx_is_key_down(param, MLX_KEY_UP) && !colision_check(new_x, new_y -= 5));
    if (mlx_is_key_down(param, MLX_KEY_DOWN) && !colision_check(new_x, new_y += 5));
    if (mlx_is_key_down(param, MLX_KEY_LEFT) && !colision_check(new_x -= 5, new_y));
    if (mlx_is_key_down(param, MLX_KEY_RIGHT) && !colision_check(new_x += 5, new_y));
}

void    create_object(int x, int y)
{
    t_object *objects;
    t_object *current;

    current = objects;
    while (objects->next != NULL)
    {
        if (objects->next == NULL)
            objects->next = objects;
        objects = objects->next;
    }

}

int main(void)
{
	t_map_info  map;
	mlx_image_t* mure;

	map = get_array_map("./map.ber");
	mlx_t* mlx = mlx_init(1920, 1080, "Test", true);
	mlx_texture_t* texture = mlx_load_png("./player.png");
	mlx_texture_t* mur = mlx_load_png("./mur.png");
	img = mlx_texture_to_image(mlx, texture);
	
	mlx_image_to_window(mlx, img, 0, 0);

	mure = mlx_texture_to_image(mlx, mur);
	mlx_image_to_window(mlx, mure, 300, 300);

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (0);
}