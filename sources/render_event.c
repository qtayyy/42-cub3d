/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:17:36 by nchok             #+#    #+#             */
/*   Updated: 2024/12/16 14:05:59 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_if_event(t_data *data)
{
	move_player(data);
	toggle_cursor(data);
	if (data->player.has_moved)
		render_raycast(data);
	return (0);
}

int	toggle_cursor(t_data *data)
{
	if (data->player.show_cursor)
		mlx_mouse_show(data->mlx, data->win);
	else
		mlx_mouse_hide(data->mlx, data->win);
	return (0);
}
