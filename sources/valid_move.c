/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:35:34 by nchok             #+#    #+#             */
/*   Updated: 2024/12/15 00:34:03 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_valid_move(t_data *data, double new_x, double new_y)
{
	int	valid_move;

	valid_move = 0;
	if (is_not_wall(data, data->player.pos_x, new_y) == 1)
	{
		data->player.pos_y = new_y;
		valid_move = 1;
	}
	if (is_not_wall(data, new_x, data->player.pos_y) == 1)
	{
		data->player.pos_x = new_x;
		valid_move = 1;
	}
	return (valid_move);
}

int	is_not_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (data->map[map_y][map_x] == '0')
		return (1);
	return (0);
}
