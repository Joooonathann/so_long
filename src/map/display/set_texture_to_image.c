#include "so_long.h"

t_texture_info	create_texture_info(int line_x, int line_y,
									int width, int height)
{
	t_texture_info	texture_info;

	texture_info.line_x = line_x;
	texture_info.line_y = line_y;
	texture_info.width = width;
	texture_info.height = height;
	return (texture_info);
}

static void	set_pixel(mlx_texture_t **texture, mlx_image_t **image,
						t_texture_info *texture_info)
{
	int			i;
	int			j;
	int			k;
	uint8_t		*pixelx;
	uint8_t		*pixeli;

	i = 0;
	while (i < texture_info->height)
	{
		j = 0;
		while (j < texture_info->width)
		{
			k = 0;
			while (k < (*texture)->bytes_per_pixel)
			{
				pixelx = &(*texture)->pixels[(((i + texture_info->start_y)* (*texture)->width) + texture_info->start_x + j) * (*texture)->bytes_per_pixel + k];
				pixeli = &(*image)->pixels[((i * texture_info->width) + j) * (*texture)->bytes_per_pixel + k];
				*pixeli = *pixelx;
				k++;
			}
			j++;
		}
		i++;
	}
}

mlx_image_t *set_texture_to_image(mlx_t *mlx, mlx_texture_t *texture,
									t_texture_info texture_info, int zoom)
{
	mlx_image_t *image;

	if (!mlx || !texture || texture_info.line_x < 0 || texture_info.line_y < 0 || texture_info.width <= 0 || texture_info.height <= 0)
		return (NULL);
	texture_info.start_x = texture_info.line_x * texture_info.width;
	texture_info.start_y = texture_info.line_y * texture_info.height;
	if ((texture_info.start_x + texture_info.width) > texture->width
			|| (texture_info.start_y + texture_info.height) > texture->height)
		return (NULL);
	image = mlx_new_image(mlx, texture_info.width, texture_info.height);
	if (!image)
		return (NULL);
	set_pixel(&texture, &image, &texture_info);
	mlx_resize_image(image, (zoom * texture_info.width), (zoom * texture_info.height));
	return (image);
}
