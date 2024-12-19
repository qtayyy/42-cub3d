/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:49:06 by nchok             #+#    #+#             */
/*   Updated: 2024/12/19 10:31:46 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map_inner_space(t_data *data, char **map, int max_h)
{
	int	i;
	int	j;
	int	max_w;

	i = 0;
	(void)data;
	while (i < max_h)
	{
		j = 0;
		max_w = ft_strlen(map[i]);
		while (map[i][j] && j < max_w)
		{
			if (map[i][j] == ' ')
			{
				if (check_closed_by_1(map, i, j, max_h) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_closed_by_1(char **map, int i, int j, int max_h)
{
	t_map_info	info;

	info.map = map;
	info.max_h = max_h;
	info.found_1 = 0;
	check_up_down(&info, i, j);
	check_left_right(&info, i, j);
	if (info.found_1 == 4)
		return (FAILURE);
	return (SUCCESS);
}

int	check_up_down(t_map_info *info, int h, int j)
{
	int	tmp;

	tmp = h;
	while (h >= 0 && j >= 0 && j < (int)ft_strlen(info->map[h]))
	{
		if (info->map[h][j] == '1')
		{
			info->found_1 += 1;
			break;
		}
		h--;
	}
	h = tmp;
	while (h < info->max_h && j >= 0 && j < (int)ft_strlen(info->map[h]))
	{
		if (info->map[h][j] == '1')
		{
			info->found_1 += 1;
			break;
		}
		h++;
	}
	return (0);
}

int	check_left_right(t_map_info *info, int h, int j)
{
	int	w;

	w = j;
	while (w >= 0 && info->map[h][w])
	{
		if (info->map[h][w] == '1')
		{
			info->found_1 += 1;
			break;
		}
		w--;
	}
	w = j;
	while (w < (int)ft_strlen(info->map[h]) && info->map[h][w])
	{
		if (info->map[h][w] == '1')
		{
			info->found_1 += 1;
			break;
		}
		w++;
	}
	return (0);
}
