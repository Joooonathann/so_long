#include "so_long.h"

static int get_size_primary(int fd)
{
    int     x;
    int     read_on;
    char    buff;
    
    buff = ' ';
    x = 0;
    read_on = 1;
    while (buff != '\n' || read_on == 0)
    {
        read_on = read(fd, &buff, 1);
        if (buff != '\n')
            x++;
    }
    return (x);
}

int get_size_map(const char *path_map, t_map_info *map)
{
    int     fd;
    int     read_on;
    int     x_tmp;
    char    buff;

    x_tmp = 0;
    fd = open(path_map, O_RDONLY);
    read_on = 1;
    map->x = get_size_primary(fd);
    while (read_on > 0)
    {
        read_on = read(fd, &buff, 1);
        if (buff == '\n' || read_on == 0)
        {
            if (x_tmp != map->x)
                return (0);
            map->y++;
            x_tmp = 0;
        }
        else
            x_tmp++;
    }
    close(fd);
    return (1);
}