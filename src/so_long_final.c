#include "so_long.h"

void	create_player(mlx_t *mlx)
{
	
}

int32_t main(void)
{
	mlx_t* mlx = mlx_init(1000, 500, "42Balls", true);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	mlx_image_to_window(mlx, img, 0, 0);
    
    mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}