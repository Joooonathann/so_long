#include "so_long.h"

static void free_items(t_items_map *items) {
    t_items_map *current = items;
    while (current != NULL) {
        t_items_map *next = current->next;
        free(current);
        current = next;
    }
}

static void add_items(int type, mlx_image_t *sprite, t_items_map **items)
{
    t_items_map *new_item = malloc(sizeof(t_items_map));
    if (new_item == NULL)
    {
        free_items(items);
        errors_controller("Error\nL'affichage de la map n'a pas pus aboutir.\n", &game.map, game.mlx);
    }
    new_item->type = type;
    new_item->sprite = sprite;
    new_item->next = *items;
    *items = new_item;
}

mlx_image_t *items_controller(char c)
{
    mlx_image_t*    img;

    if (c == 'E')
    {
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/exit.png"));
        mlx_resize_image(img, 64, 64);
        add_items(1, img, items);
    }
    else if (c == 'C')
    {
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/collect.png"));
        mlx_resize_image(img, 64, 64);
        add_items(1, img, items);
    }
    else if (c == 'P')
    {
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/player.png"));
        mlx_resize_image(img, 64, 64);
    }
    return (img);
}

static void    display_tiles(char c, int y, int x, t_global game, t_items_map **items)
{
    mlx_image_t*    img;

    if (c == '1')
    {
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/wall.png"));
        mlx_resize_image(img, 64, 64);
        add_items(1, img, items);
    }
    else if (c == '0')
    {
        img = mlx_texture_to_image(game.mlx, mlx_load_png("./assets/background.png"));
        mlx_resize_image(img, 64, 64);
    }
    else
        img = items_controller(c);
    if (!img || mlx_image_to_window(game.mlx, img, x * 64, y * 64) < 0)
        errors_controller("Error\nL'affichage de la map n'a pas pus aboutir.\n", &game.map, game.mlx);
}

t_items_map    *display_map(t_global *game)
{
    int a;
    int b;
    t_items_map *items;

    items = NULL
    a = 0;
    while (a < game->map.y)
    {
        b = 0;
        while (b < game->map.x)
        {
           display_tiles(game->map.map[a][b], a, b, &game);
           b++;
        }
        a++;
    }
    return (items);
}