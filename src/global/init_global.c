#include "so_long.h"

t_global	init_global(mlx_t **mlx, t_map_info *map)
{
    t_global    result;

    result.mlx = *mlx;
    result.map = *map;
    return (result);
}