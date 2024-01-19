#include "so_long.h"
#include <stdio.h>

void    errors_controller(int error_code, t_map_info *map)
{
	if (error_code == 1)
		printf("Error\nLe fichier n'est pas valide.\n");
	else if (error_code == 2)
		printf("Error\nLa map n'est pas au normes.\n");
	else if (error_code == 3)
		printf("Error\nL'allocation de mémoire a échouée.\n");
	else if (error_code == 4)
		printf("Error\nLa map n'est pas rectangle.\n");
	else if (error_code == 5)
		printf("Error\nLa map n'est pas entouré de mur.\n");
	else if (error_code == 6)
		printf("Error\nLa map contient des objets invalide.\n");
	else if (error_code == 7)
		printf("Error\nLe flood fill n'a pas pus aboutir.\n");
	if (map->map != NULL)
		destroy_map(*map);
	exit(1);
}