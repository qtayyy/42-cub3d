/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:17:36 by nchok             #+#    #+#             */
/*   Updated: 2024/12/15 00:30:04 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_if_event(t_data *data)
{
	move_player(data);
	if (data->player.has_moved)
		render_raycast(data);
	return (0);
}
