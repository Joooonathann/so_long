#include "so_long.h"

static void	set_pixel(mlx_texture_t **texture, mlx_image_t **image, int width, int height, int start_x, int start_y)
{
	int         i;
	int         j;
	int         k;
	uint8_t     *pixelx;
	uint8_t     *pixeli;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			k = 0;
			while (k < (*texture)->bytes_per_pixel)
			{
				pixelx = &(*texture)->pixels[(((i + start_y) * (*texture)->width) + start_x + j) * (*texture)->bytes_per_pixel + k];
				pixeli = &(*image)->pixels[((i * width) + j) * (*texture)->bytes_per_pixel + k];
				*pixeli = *pixelx;
				k++;
			}
			j++;
		}
		i++;
	}
}

mlx_image_t *set_texture_to_image(mlx_t *mlx, mlx_texture_t *texture, int line_x, int line_y, int width, int height, int zoom_x, int zoom_y)
{
	int         start_x;
	int         start_y;
	mlx_image_t *image;

	if (!mlx || !texture || line_x < 0 || line_y < 0 || width <= 0 || height <= 0)
		return (NULL);
	start_x = line_x * width;
	start_y = line_y *height;
	if ((start_x + width) > texture->width || (start_y + height) > texture->height)
		return (NULL);
	image = mlx_new_image(mlx, width, height);
	if (!image)
		return (NULL);
	set_pixel(&texture, &image, width, height, start_x, start_y);
	if (zoom_x != 0 || zoom_y != 0)
		mlx_resize_image(image, zoom_x, zoom_y);
	return (image);
}