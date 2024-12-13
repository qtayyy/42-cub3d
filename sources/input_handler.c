/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:47:16 by nchok             #+#    #+#             */
/*   Updated: 2024/12/13 21:20:42 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_cub3d(data);
	if (keycode == KEY_W)
		data->player.move_y = 1;
	if (keycode == KEY_S)
		data->player.move_y = -1;
	if (keycode == KEY_A)
		data->player.move_x = -1;
	if (keycode == KEY_D)
		data->player.move_x = 1;
	return (0);
}

int	key_release_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_cub3d(data);
	if (keycode == KEY_W && data->player.move_y == 1)
		data->player.move_y = 0;
	if (keycode == KEY_S && data->player.move_y == -1)
		data->player.move_y = 0;
	if (keycode == KEY_A && data->player.move_x == -1)
		data->player.move_x = 0;
	if (keycode == KEY_D && data->player.move_x == 1)
		data->player.move_x = 0;
	return (0);
}
void	input_handler(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, data);
// 	mlx_hook(data->win, 17, 1L << 17, close_window, data);
}