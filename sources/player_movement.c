/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:49:43 by nchok             #+#    #+#             */
/*   Updated: 2024/12/14 01:35:10 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_player(t_data *data)
{
	int		move_count;

	move_count = 0;
	if (data->player.movement == FORWARD)
		move_count = move_forward(data);
	if (data->player.movement == BACKWARD)
		move_count = move_backward(data);
	if (data->player.movement == LEFT)
		move_count = move_left(data);
	if (data->player.movement == RIGHT)
		move_count = move_right(data);
	return (move_count);
}

int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;
	int	valid_move;
	
	new_x = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVE_SPEED;
	valid_move = check_valid_move(data, new_x, new_y);
	return (valid_move);
}

int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;
	int	valid_move;
	
	new_x = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVE_SPEED;
	valid_move = check_valid_move(data, new_x, new_y);
	return (valid_move);
}

int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;
	int	valid_move;
	
	new_x = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	valid_move = check_valid_move(data, new_x, new_y);
	return (valid_move);
}

int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;
	int	valid_move;
	
	new_x = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	valid_move = check_valid_move(data, new_x, new_y);
	return (valid_move);
}
