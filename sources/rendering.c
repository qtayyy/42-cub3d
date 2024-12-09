/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:00 by qtay              #+#    #+#             */
/*   Updated: 2024/12/09 09:25:01 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_screen_pixels(t_data *data)
{
	int	i;

	i = -1;
	if (data->screen_pixels != NULL)
		free_double_arr((void **)data->screen_pixels);
	data->screen_pixels = ft_calloc(WIN_HEIGHT + 1, sizeof(int *));
	if (data->screen_pixels == NULL)
	{
		printf("Failed to allocate memory for screen_pixels\n");
		exit(1); // Allocation failed, handle the error
	}
	while (++i < WIN_HEIGHT)
	{
		data->screen_pixels[i] = ft_calloc(WIN_WIDTH + 1, sizeof(int));
		if (data->screen_pixels[i] == NULL)
		{
			printf("screen pixel[%d] init fail\n", i);
			exit(1); // Exit, or handle the memory cleanup and return gracefully
		}
	}
}

void	put_pixel(t_img	*image, int x, int y, int color)
{
	int	pixel;

	pixel = (y * image->line_length + (x * (image->bits_per_pixel / 8))) / 4;
	image->addr[pixel] = color;
}

void	set_frame_pixel(t_data *data, t_img	*image, int x, int y)
{
	if (data->screen_pixels[y][x])
		put_pixel(image, x, y, data->screen_pixels[y][x]);
	else if (y < WIN_HEIGHT / 2)
		put_pixel(image, x, y, (int)data->tex_info.hex_ceiling);
	else
		put_pixel(image, x, y, (int)data->tex_info.hex_floor);
}

void	render_frame(t_data *data)
{
	int		x;
	int		y;
	t_img	image;

	image.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	image.addr = (int *)mlx_get_data_addr(image.img,
			&image.bits_per_pixel, &image.line_length, &image.endian);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			set_frame_pixel(data, &image, x, y);
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	render_raycast(t_data *data)
{
	init_screen_pixels(data);
	init_ray(&data->ray);
	raycasting(data, &data->player);
	render_frame(data);
}
