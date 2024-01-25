#include "so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct objects
{
    int type;
    int is_active;
    mlx_image_t* sprite;
    struct objects *next;
} t_object;



static int  create_map()
{
	
}

mlx_image_t* img;
t_object *wall;
t_object *objs = NULL;

int collision_check(int new_x, int new_y)
{
    t_object *current;
    current = objs;

    while (current != NULL)
    {
        if (!(new_x + img->width <= current->sprite->instances[0].x ||
              new_x >= current->sprite->instances[0].x + current->sprite->width ||
              new_y + img->height <= current->sprite->instances[0].y ||
              new_y >= current->sprite->instances[0].y + current->sprite->height) && current->is_active)
        {
            return 1; // Collision détectée
        }
        printf("Collision with object at (%d, %d)\n", current->sprite->instances[0].x, current->sprite->instances[0].y);
        current = current->next;
    }

    return 0; // Aucune collision détectée
}


int take_item(int new_x, int new_y)
{
    t_object *current;
    current = objs;

    while (current != NULL)
    {
        int img_center_x = new_x + img->width / 2;
        int img_center_y = new_y + img->height / 2;
        int obj_center_x = current->sprite->instances[0].x + current->sprite->width / 2;
        int obj_center_y = current->sprite->instances[0].y + current->sprite->height / 2;

        int combined_radius = current->sprite->width;

        int diff_x = img_center_x - obj_center_x;
        int diff_y = img_center_y - obj_center_y;

        if (current->type == 2 &&
            diff_x * diff_x < (current->sprite->width / 2 + combined_radius) * (current->sprite->width / 2 + combined_radius) &&
            diff_y * diff_y < (current->sprite->height / 2 + combined_radius) * (current->sprite->height / 2 + combined_radius))
        {
            current->sprite->enabled = false;
            current->is_active = 0;
            return 1;
        }
        current = current->next;
    }

    return 0;
}


void hook(void *param)
{
    mlx_t *mlx;
    mlx = param;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);

    int new_x = img->instances[0].x;
    int new_y = img->instances[0].y;

    if (mlx_is_key_down(param, MLX_KEY_UP) && !collision_check(new_x, new_y - 5))
    {
        new_y -= 5;
        printf("Moving UP\n");
    }
    if (mlx_is_key_down(param, MLX_KEY_DOWN) && !collision_check(new_x, new_y + 5))
    {
        new_y += 5;
        printf("Moving DOWN\n");
    }
    if (mlx_is_key_down(param, MLX_KEY_LEFT) && !collision_check(new_x - 5, new_y))
    {
        new_x -= 5;
        printf("Moving LEFT\n");
    }
    if (mlx_is_key_down(param, MLX_KEY_RIGHT) && !collision_check(new_x + 5, new_y))
    {
        new_x += 5;
        printf("Moving RIGHT\n");
    }
    if (mlx_is_key_down(param, MLX_KEY_F) && take_item(new_x, new_y))
    {
        printf("CAPTURE the item\n");
    }

    img->instances[0].x = new_x;
    img->instances[0].y = new_y;
}



void    create_object(int is_active, mlx_image_t* sprite, int type)
{
    t_object *new;
    t_object *current;

    new = malloc(sizeof(t_object));
    new->is_active = is_active;
    new->sprite = sprite;
    new->type = type;
    new->next = NULL;

    if (objs == NULL) {
        objs = new;
    } 
    else {
        current = objs;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
}

mlx_image_t *get_last_object()
{
    t_object *current;
    current = objs;
    while (current->next != NULL)
        current = current->next;
    return (current->sprite);
}

void display_map(mlx_t* mlx, t_map_info map)
{
    int a, b, z, p;
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
                create_object(1, mlx_texture_to_image(mlx, mlx_load_png("./mur.png")), 1);
                mlx_image_to_window(mlx, get_last_object(), z, p);
            }
            else if (map.map[a][b] == 'C')
            {
                create_object(1, mlx_texture_to_image(mlx, mlx_load_png("./egg.png")), 2);
                mlx_image_to_window(mlx, get_last_object(), z, p);
            }
            z += 100;
            b++;
        }
        p += 100;
        a++;
    }
}

void	ft_lstclear(t_object *lst)
{
	t_object	*current;
	t_object	*next;

	if (!lst)
		return ;
	current = lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	lst = NULL;
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
    mlx_resize_image(img, 50, 50);
    mlx_image_to_window(mlx, img, 110, 110);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
    while (objs != NULL)
    {
        mlx_delete_image(mlx, objs->sprite);
        objs = objs->next;
    }
    ft_lstclear(objs);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (0);
}