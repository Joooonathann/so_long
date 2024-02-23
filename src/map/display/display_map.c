#include "so_long.h"

mlx_image_t    *resize(mlx_image_t *img)
{
    mlx_resize_image(img, 64, 64);
    return (img);
}

static void    display_tiles(char c, int y, int x, t_global game)
{
    mlx_image_t*    img;

    if (c == '1')
    {
        mlx_image_to_window(game.mlx, resize(mlx_texture_to_image(game.mlx, mlx_load_png("./assets/background.png"))), x * 64, y * 64);
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/wall.png"));
    }
    else
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/background.png"));
    if (!img || !mlx_resize_image(img, 64, 64) || mlx_image_to_window(game.mlx, img, x * 64, y * 64) < 0)
        errors_controller("Error\nL'affichage de la map n'a pas pus aboutir.\n", &game.map);
}

void    display_map(t_global game)
{
    int a;
    int b;

    a = 0;
    while (a < game.map.y)
    {
        b = 0;
        while (b < game.map.x)
        {
           display_tiles(game.map.map[a][b], a, b, game);
           b++;
        }
        a++;
    }
}