/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:52:50 by qtay              #+#    #+#             */
/*   Updated: 2025/02/02 19:01:20 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	run_dda_algo(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->start_x < ray->start_y)
		{
			ray->start_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = VERTICAL;
		}
		else
		{
			ray->start_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = HORIZONTAL;
		}
		if (data->map[ray->map_y][ray->map_x] != '0')
			hit = 1;
	}
}

/**
 * Can divide perp_wall_dist by cos(camera_x) to simulate fisheye effect
 */
void	calculate_line_height(t_ray *ray, t_player *player)
{
	if (ray->side == VERTICAL)
	{
		ray->perp_wall_dist = (ray->start_x - ray->deltadist_x);
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		ray->perp_wall_dist = (ray->start_y - ray->deltadist_y);
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (WIN_HEIGHT - ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (WIN_HEIGHT + ray->line_height) / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

int	get_texture_index(t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		if (ray->dir_x < 0)
			return (WEST);
		return (EAST);
	}
	else
	{
		if (ray->dir_y > 0)
			return (SOUTH);
		return (NORTH);
	}
}

void	update_screen_pixel(t_data *data, t_ray *ray,
		t_textures *tex_info, int x)
{
	int		y;
	int		color;

	tex_info->tex_index = get_texture_index(ray);
	tex_info->tex_x = (int)(ray->wall_x * (double)data->tex_info.size);
	if ((ray->side == VERTICAL && ray->dir_x > 0)
		|| (ray->side == HORIZONTAL && ray->dir_y < 0))
		tex_info->tex_x = data->tex_info.size - tex_info->tex_x - 1;
	tex_info->increment = (double)data->tex_info.size / ray->line_height;
	tex_info->tex_pos = (ray->draw_start + (ray->line_height - WIN_HEIGHT) / 2)
		* tex_info->increment;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_info->tex_y = (int)tex_info->tex_pos;
		tex_info->tex_pos += tex_info->increment;
		color = data->textures[tex_info->tex_index]
		[data->tex_info.size * tex_info->tex_y + tex_info->tex_x];
		if (color > 0)
			data->screen_pixels[y][x] = color;
		y++;
	}
}

void	raycasting(t_data *data, t_player *player)
{
	t_ray	ray;
	int		x;

	x = -1;
	ray = data->ray;
	while (++x < WIN_WIDTH)
	{
		init_raycasting(x, &ray, player);
		init_dda_algo(&ray, player);
		run_dda_algo(data, &ray);
		calculate_line_height(&ray, player);
		update_screen_pixel(data, &ray, &data->tex_info, x);
	}
}
