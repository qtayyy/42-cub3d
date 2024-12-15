/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:47:16 by nchok             #+#    #+#             */
/*   Updated: 2024/12/16 01:43:36 by nchok            ###   ########.fr       */
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
	mlx_hook(data->win, DestroyNotify, NoEventMask, exit_cub3d, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask , key_release_handler, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_motion_handler, data);
}

int	mouse_motion_handler(int x, int y, t_data *data)
{
	// static int		old_x;
	// static int		old_y;
	// int				diff_x;
	int				half_width;

	(void)y;
	half_width = WIN_WIDTH / 2;
	if (x > half_width)
		data->player.has_moved += rotate_clockwise(data);
	else if (x < half_width)
		data->player.has_moved += rotate_anticlockwise(data);
	printf("-------BEFORE-------\n");
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	mlx_mouse_move(data->mlx, data->win, half_width, WIN_HEIGHT);
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	printf("-------AFTER-------\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	// diff_x = x - old_x;
	// if (diff_x > 0)
	// 	data->player.has_moved += rotate_anticlockwise(data);
	// else if (diff_x < 0)
	// 	data->player.has_moved += rotate_clockwise(data);
	// mlx_mouse_get_pos(data->mlx, data->win, &old_x, &old_y);
	// printf("old_x: %d\n", old_x);
	// printf("old_y: %d\n", old_y);
	// mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
	
}
