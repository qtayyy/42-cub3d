/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:53:50 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 17:52:45 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_me(int *i, int *j, int *row, int *col)
{
	if (*row == *i && *col == *j)
		return (TRUE);
	return (FALSE);
}

int	process_row(t_map_info *info, int i, int j, int row)
{
	int	col;

	col = j - 1;
	while (col <= j + 1 && col < info->max_w)
	{
		if (is_me(&i, &j, &row, &col) == TRUE || col < 0)
		{
			col++;
			continue ;
		}
		if (check_cell(info, row, col) == FAILURE)
			return (FAILURE);
		col++;
	}
	return (SUCCESS);
}

int	check_cell(t_map_info *info, int row, int col)
{
	if (is_valid_position(row, col, info->max_h, info->max_w)
		&& info->map[row][col])
	{
		if (is_0_or_player(info->map[row][col]) == TRUE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	is_valid_position(int row, int col, int max_h, int max_w)
{
	return (row >= 0 && row < max_h && col >= 0 && col < max_w);
}
