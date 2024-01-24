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
mlx_image_t* mure;
t_object *wall;
t_object *objs = NULL;

int colision_check(int new_x, int new_y)
{
    int wall_width = 100;
    int wall_height = 100;

    t_object *current;
    current = objs;
    while (current->next != NULL)
    {
        printf("%d  %d \n", current->x, current->y);
        if ((new_x + img->width <= current->x ||
          new_x >= current->x + wall_width ||
          new_y + img->height <= current->y ||
          new_y >= current->y + wall_height))
        {
        img->instances[0].x = new_x;
        img->instances[0].y = new_y;
        current = current->next;
        return (1);
        }
        current = current->next;
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
    t_object *new;
    t_object *current;

    new = malloc(sizeof(t_object));
    new->x = x;
    new->y = y;
    new->next = NULL;

    if (objs == NULL) {
        objs = new;
    } else {
        current = objs;
        while (current->next != NULL)
            current = current->next;

        current->next = new;
    }
}

void display_map(mlx_t* mlx, t_map_info map)
{
    int a, b, z, p;
    mlx_texture_t* mur = mlx_load_png("./mur.png");
    mure = mlx_texture_to_image(mlx, mur);
    a = 0;
    p = 0;
    while (a < map.y)
    {
        b = 0;
        z = 0;
        while (map.map[a][b])
        {
            if (map.map[a][b] == '1')
            {
                create_object(z, p);
                mlx_image_to_window(mlx, mure, z, p);
            }
            z += 100;
            b++;
        }
        p += 100;
        a++;
    }
}

int main(void)
{
	t_map_info  map;

	map = get_array_map("./map.ber");
	mlx_t* mlx = mlx_init(100 * map.x, 100 * map.y, "Test", true);
	mlx_texture_t* texture = mlx_load_png("./player.png");
	img = mlx_texture_to_image(mlx, texture);

	mlx_loop_hook(mlx, &hook, mlx);
    display_map(mlx, map);
    mlx_image_to_window(mlx, img, 110, 110);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (0);
}