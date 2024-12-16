/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:47:16 by nchok             #+#    #+#             */
/*   Updated: 2024/12/16 18:24:36 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press_handler(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
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
	if (keycode == KEY_LCTRL)
		change_cursor_visibility(&data->player);
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
	static int		old_x;
	static int		old_y;
	int				diff_x;

	(void)y;
	mlx_mouse_hide(data->mlx, data->win);
	diff_x = x - old_x;
	if (diff_x > 0)
		data->player.has_moved += rotate_anticlockwise(data);
	else if (diff_x < 0)
		data->player.has_moved += rotate_clockwise(data);
	mlx_mouse_get_pos(data->mlx, data->win, &old_x, &old_y);
	if (old_x > WIN_WIDTH - EDGE_WIND)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (old_x < EDGE_WIND)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	change_cursor_visibility(t_player *player)
{
	if (player->show_cursor)
		player->show_cursor = 0;
	else
		player->show_cursor = 1;
	return (0);
}
