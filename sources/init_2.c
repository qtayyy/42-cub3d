/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:19 by qtay              #+#    #+#             */
/*   Updated: 2025/01/23 19:05:20 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_dir(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	else if (player->dir == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	else if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		err_msg("malloc error");
		exit_cub3d(data, 1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (data->win == NULL)
	{
		err_msg("malloc error");
		exit_cub3d(data, 1);
	}
	return ;
}

// static void	init_texture_img(t_data *data, t_img *image, char *path)
// {
// 	image->img = NULL;
// 	image->addr = NULL;
// 	image->bits_per_pixel = 0;
// 	image->line_length = 0;
// 	image->endian = 0;
// 	image->img = mlx_xpm_file_to_image(data->mlx, path,
// 			&data->tex_info.size, &data->tex_info.size);
// 	image->addr = (int *)mlx_get_data_addr(image->img,
// 			&image->bits_per_pixel, &image->line_length, &image->endian);
// }

// static void	init_texture_img(t_data *data, t_img *image, char *path)
// {
// 	image->img = NULL;
// 	image->addr = NULL;
// 	image->bits_per_pixel = 0;
// 	image->line_length = 0;
// 	image->endian = 0;

// 	// Load XPM image
// 	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->width, &image->height);
// 	if (!image->img)
// 	{
// 		err_msg("Failed to load texture");
// 		exit_cub3d(data, 1);
// 	}

// 	// Get image address for pixel manipulation
// 	image->addr = (int *)mlx_get_data_addr(image->img,
// 		&image->bits_per_pixel, &image->line_length, &image->endian);
// 	if (!image->addr)
// 	{
// 		err_msg("Failed to get texture address");
// 		exit_cub3d(data, 1);
// 	}
// }

// static int	*xpm_to_img(t_data *data, char *path)
// {
// 	t_img	tmp;
// 	int		*buffer;

// 	init_texture_img(data, &tmp, path);
// 	buffer = ft_calloc((TEXTURE_SIZE) * (TEXTURE_SIZE), sizeof(int));
// 	if (buffer == NULL)
// 	{
// 		err_msg("malloc error");
// 		exit_cub3d(data, 1);
// 	}
// 	ft_memcpy(buffer, tmp.addr, (TEXTURE_SIZE) * (TEXTURE_SIZE) * sizeof(int));
// 	mlx_destroy_image(data->mlx, tmp.img);
// 	return (buffer);
// }

// void	load_texture_img(t_data *data)
// {
// 	data->textures = ft_calloc(5, sizeof(int *));
// 	if (data->textures == NULL)
// 	{
// 		err_msg("malloc error");
// 		exit_cub3d(data, 1);
// 	}
// 	data->textures[NORTH] = xpm_to_img(data, data->tex_info.north);
// 	data->textures[SOUTH] = xpm_to_img(data, data->tex_info.south);
// 	data->textures[EAST] = xpm_to_img(data, data->tex_info.east);
// 	data->textures[WEST] = xpm_to_img(data, data->tex_info.west);
// }

static int	*xpm_to_texture(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;

	// Load the image
	tmp.img = mlx_xpm_file_to_image(data->mlx, path, &data->tex_info.size, &data->tex_info.size);
	if (tmp.img == NULL)
	{
		err_msg("Failed to load texture");
		exit_cub3d(data, 1);
	}

	// Get image data address
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);

	// Allocate buffer for texture pixels
	buffer = ft_calloc(data->tex_info.size * data->tex_info.size, sizeof(int));
	if (buffer == NULL)
	{
		err_msg("Memory allocation error");
		exit_cub3d(data, 1);
	}

	// Copy pixel data into the buffer
	ft_memcpy(buffer, tmp.addr, data->tex_info.size * data->tex_info.size * sizeof(int));

	// Free the temporary image
	mlx_destroy_image(data->mlx, tmp.img);

	return (buffer);
}

void	load_texture_img(t_data *data)
{
	// Allocate memory for texture array (4 directions)
	data->textures = ft_calloc(4, sizeof(int *));
	if (data->textures == NULL)
	{
		err_msg("Memory allocation error");
		exit_cub3d(data, 1);
	}

	// Load each texture
	data->textures[NORTH] = xpm_to_texture(data, data->tex_info.north);
	data->textures[SOUTH] = xpm_to_texture(data, data->tex_info.south);
	data->textures[EAST] = xpm_to_texture(data, data->tex_info.east);
	data->textures[WEST] = xpm_to_texture(data, data->tex_info.west);
}
