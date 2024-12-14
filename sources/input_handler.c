/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:47:16 by nchok             #+#    #+#             */
/*   Updated: 2024/12/15 02:28:37 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_cub3d(data);
	if (keycode == KEY_W)
		data->player.movement = FORWARD;
	if (keycode == KEY_S)
		data->player.movement = BACKWARD;
	if (keycode == KEY_A)
		data->player.movement = LEFT;
	if (keycode == KEY_D)
		data->player.movement = RIGHT;
	if (keycode == KEY_LEFT)
		data->player.movement = ANTICLOCKWISE;
	if (keycode == KEY_RIGHT)
		data->player.movement = CLOCKWISE;
	return (0);
}

int	key_release_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_cub3d(data);
	if (keycode == KEY_W && data->player.movement == FORWARD)
		data->player.movement = 0;
	if (keycode == KEY_S && data->player.movement == BACKWARD)
		data->player.movement = 0;
	if (keycode == KEY_A && data->player.movement == LEFT)
		data->player.movement = 0;
	if (keycode == KEY_D && data->player.movement == RIGHT)
		data->player.movement = 0;
	if (keycode == KEY_LEFT && data->player.movement == ANTICLOCKWISE)
		data->player.movement = 0;
	if (keycode == KEY_RIGHT && data->player.movement == CLOCKWISE)
		data->player.movement = 0;
	return (0);
}
void	input_handler(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, data);
// 	mlx_hook(data->win, 17, 1L << 17, close_window, data);
}