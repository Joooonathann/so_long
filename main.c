#include "so_long.h"
#include <stdio.h>

static int  create_map()
{
    
}

int main(void)
{
    t_map_info  map;

    map = get_array_map("./map.ber");
    if (map.is_error)
        printf("error");
    else if (map.is_valid == 0)
    {
        destroy_map(map);
        return (0);
    }
    else
    {
        int i = 0;
        while (i < map.y)
            printf("%s\n", map.map[i++]);
        destroy_map(map);
    }
    return (0);
}