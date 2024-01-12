#include "so_long.h"

void    set_object_map(const char *path_map, t_map_info *map)
{
    int     fd;
    int     read_on;
    char    buff;
    int     a;
    int     b;

    a = 0;
    b = 0;
    fd = open(path_map, O_RDONLY);
    read_on = 1;
    while (read_on > 0)
    {
        read_on = read(fd, &buff, 1);
        if (buff == '\n' || read_on == 0)
        {
            map->map[a][b] = '\0';
            b = 0;
            a++;
        }
        else
            map->map[a][b++] = buff;
    }
    close(fd);
}