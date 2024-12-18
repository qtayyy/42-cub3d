/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:40:56 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 17:55:01 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	scan_map(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && i <= height)
	{
		j = 0;
		while (map[i][j] && j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'X')
			{
				if (check_surrounding(map, i, j, height) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_surrounding(char **map, int i, int j, int max_h)
{
	int			row;
	int			result;
	t_map_info	info;

	info.map = map;
	info.max_h = max_h;
	row = i - 1;
	while (row <= i + 1 && row < max_h)
	{
		if (row < 0 || !map[row])
		{
			row++;
			continue ;
		}
		info.max_w = (int)ft_strlen(map[row]);
		result = process_row(&info, i, j, row);
		if (result == FAILURE)
			return (FAILURE);
		row++;
	}
	return (SUCCESS);
}

int	is_0_or_player(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

void	replace_space_to_1(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	check_map_elements(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("01NSEW", map[i][j]) == NULL)
				return (FAILURE);
			else if (ft_strchr("NSEW", map[i][j]))
			{
				data->player.dir = map[i][j];
				data->map[i][j] = '0';
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
			}
			j++;
		}
	}
	return (SUCCESS);
}
