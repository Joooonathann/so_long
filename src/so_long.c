#include "so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

static int  create_map()
{
	
}

mlx_image_t* img;

void hook(void* param)
{
    mlx_t* mlx;
    mlx = param;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);

    int new_x = img->instances[0].x;
    int new_y = img->instances[0].y;

    if (mlx_is_key_down(param, MLX_KEY_UP))
        new_y -= 5;
    if (mlx_is_key_down(param, MLX_KEY_DOWN))
        new_y += 5;
    if (mlx_is_key_down(param, MLX_KEY_LEFT))
        new_x -= 5;
    if (mlx_is_key_down(param, MLX_KEY_RIGHT))
        new_x += 5;

    // Vérification de la collision avec le mur
    int wall_x = 300; // Coordonnées X du coin supérieur gauche du mur
    int wall_y = 300; // Coordonnées Y du coin supérieur gauche du mur
    int wall_width = 100; // Largeur du mur
    int wall_height = 100; // Hauteur du mur

    if ((new_x + img->width <= wall_x ||
          new_x >= wall_x + wall_width ||
          new_y + img->height <= wall_y ||
          new_y >= wall_y + wall_height))
    {
        // Mettre à jour la position uniquement si aucune collision avec le mur n'est détectée
        img->instances[0].x = new_x;
        img->instances[0].y = new_y;
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