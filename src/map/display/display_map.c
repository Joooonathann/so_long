#include "so_long.h"

void    display_map(mlx_t* mlx, t_map_info map)
{
    int a;
    int b;

    a = 0;
    while (a < map.y)
    {
        b = 0;
        while (b < map.x)
        {
            if (map.map[a][b] == '1')
            {

            }
            else if (map.map[a][b] == 'P')
            {

            }
            else if (map.map[a][b] == 'C')
            {

            }
            else if (map.map[a][b] == 'E')
            {
                
            }
            b++;
        }
        a++;
    }
}