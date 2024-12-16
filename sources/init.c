/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:19:34 by qtay              #+#    #+#             */
/*   Updated: 2024/12/16 14:04:42 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->start_x = 0.0;
	ray->start_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->perp_wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->movement = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->show_cursor = 0;
}

void	init_textures_info(t_textures *tex_info)
{
	tex_info->size = TEXTURE_SIZE;
	tex_info->north = NULL;
	tex_info->south = NULL;
	tex_info->east = NULL;
	tex_info->west = NULL;
	tex_info->floor = NULL;
	tex_info->ceiling = NULL;
	tex_info->hex_floor = 0x0;
	tex_info->hex_ceiling = 0x0;
	tex_info->tex_index = 0;
	tex_info->tex_x = 0;
	tex_info->tex_y = 0;
	tex_info->increment = 0.0;
	tex_info->tex_pos = 0.0;
}

void	init_file_info(t_cubfile *file_info)
{
	file_info->file_rows = 0;
	file_info->file_max_columns = 0;
	file_info->cub_file = NULL;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_rows = 0;
	data->textures = NULL;
	data->screen_pixels = NULL;
	init_file_info(&data->file_info);
	init_textures_info(&data->tex_info);
	init_player(&data->player);
	init_ray(&data->ray);
}
