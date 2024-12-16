/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:28:25 by nchok             #+#    #+#             */
/*   Updated: 2024/12/16 18:53:59 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_enclosed_space(char **map, int rows)
{
	char	**temp_map;

	temp_map = duplicate_map(map, rows);
	if (temp_map == NULL)
		return (FAILURE);
	if (flood_fill(temp_map, rows) == FAILURE)
	{
		free_double_arr((void **)temp_map);
		return (FAILURE);
	}
	free_double_arr((void **)temp_map);
	return (SUCCESS);
}

char	**duplicate_map(char **map, int rows)
{
	char	**temp_map;
	int		i;

	i = 0;
	temp_map = ft_calloc(rows + 1, sizeof(char *));
	if (temp_map == NULL)
		return (NULL);
	while (map[i])
	{
		temp_map[i] = ft_strdup(map[i]);
		if (temp_map[i] == NULL)
		{
			free_double_arr((void **)temp_map);
			return (NULL);
		}
		i++;
	}
	return (temp_map);
}

int	flood_fill(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				flood_fill_recursive(map, i, j, height);
			j++;
		}
		i++;
	}
	if (scan_map(map, height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	flood_fill_recursive(char **map, int i, int j, int height)
{
	if (i < 0 || i >= height || j < 0 || j >= (int)ft_strlen(map[i])
		|| map[i][j] == '1')
		return ;
	if (map[i][j] == ' ')
	{
		map[i][j] = 'X';
		flood_fill_recursive(map, i + 1, j, height);
		flood_fill_recursive(map, i - 1, j, height);
		flood_fill_recursive(map, i, j + 1, height);
		flood_fill_recursive(map, i, j - 1, height);
	}
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == '\0')
		return ;
}
