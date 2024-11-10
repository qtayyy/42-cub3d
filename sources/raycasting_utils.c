/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:29:36 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 16:30:13 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x; // dir_x + portion of the camera vector is the FoV
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)(player->pos_x);
	ray->map_y = (int)(player->pos_y);
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	init_dda_algo(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0) // if ray is going left
	{
		ray->step_x = -1;
		ray->start_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else // if ray is going right
	{
		ray->step_x = 1;
		ray->start_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0) // if ray is going up
	{
		ray->step_y = -1;
		ray->start_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else // if ray is going down
	{
		ray->step_y = 1;
		ray->start_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}
