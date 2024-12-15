/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:28:50 by nchok             #+#    #+#             */
/*   Updated: 2024/12/15 04:40:21 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rotate_player(t_data *data)
{
	if (data->player.movement == CLOCKWISE)
		rotate_clockwise(data);
	else if (data->player.movement == ANTICLOCKWISE)
		rotate_anticlockwise(data);
	return (1);
}

int	rotate_clockwise(t_data *data)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;
	
	p = &data->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ROTATE_STEP) - p->dir_y * sin(ROTATE_STEP);
	p->dir_y = old_dir_x * sin(ROTATE_STEP) + p->dir_y * cos(ROTATE_STEP);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ROTATE_STEP) - p->plane_y * sin(ROTATE_STEP);
	p->plane_y = old_plane_x * sin(ROTATE_STEP) + p->plane_y * cos(ROTATE_STEP);
	return (1);
}

int	rotate_anticlockwise(t_data *data)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;
	
	p = &data->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-ROTATE_STEP) - p->dir_y * sin(-ROTATE_STEP);
	p->dir_y = old_dir_x * sin(-ROTATE_STEP) + p->dir_y * cos(-ROTATE_STEP);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-ROTATE_STEP) - p->plane_y * sin(-ROTATE_STEP);
	p->plane_y = old_plane_x * sin(-ROTATE_STEP) + p->plane_y * cos(-ROTATE_STEP);
	return (1);
}
