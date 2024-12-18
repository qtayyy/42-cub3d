/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:40:56 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 16:57:51 by nchok            ###   ########.fr       */
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
	int	max_w;
	int	row;
	int	col;

	max_w = ft_strlen(map[i]);
	row = i - 1;
	while (row <= i + 1)
	{
		col = j - 1;
		while (col <= j + 1)
		{
			if (is_me(&i, &j, &row, &col) == TRUE)
				continue;
			if (row >= 0 && row < max_h && col >= 0 && col < max_w)
			{
				if (is_0_or_player(map[row][col]) == TRUE)
					return (FAILURE);
			}
			col++;
		}
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
