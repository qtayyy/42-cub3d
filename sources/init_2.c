/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:19 by qtay              #+#    #+#             */
/*   Updated: 2024/12/15 04:36:27 by nchok            ###   ########.fr       */
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
		return ; // some error msg
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (data->win == NULL)
		return ; // some error msg
	return ;
}

static void	init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->tex_info.size, &data->tex_info.size);
	image->addr = (int *)mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
}

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc((TEXTURE_SIZE) * (TEXTURE_SIZE), sizeof(int));
	ft_memcpy(buffer, tmp.addr, (TEXTURE_SIZE) * (TEXTURE_SIZE) * sizeof(int));
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	load_texture_img(t_data *data)
{
	data->textures = ft_calloc(5, sizeof(int *));
	if (data->textures == NULL)
		return ;
	data->textures[NORTH] = xpm_to_img(data, data->tex_info.north);
	data->textures[SOUTH] = xpm_to_img(data, data->tex_info.south);
	data->textures[EAST] = xpm_to_img(data, data->tex_info.east);
	data->textures[WEST] = xpm_to_img(data, data->tex_info.west);
}
