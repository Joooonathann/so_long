#include "so_long.h"

static int  ft_strlen(const char *str) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

static int  ft_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return ((int)(*s1) - (int)(*s2));
}

int has_ber_extension(const char *filename) {
    int len = ft_strlen(filename);
    
    if (len >= 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
        return (1);
    else
        return (0);
}

int is_valid_path(const char *path_map)
{
    int fd;
    
    fd = open(path_map, O_RDONLY);
    if ((fd < -1) || (read(fd, 0, 0) == -1))
        return (0);
    close(fd);
    if (!has_ber_extension(path_map))
        return (0);
    return (1);
}