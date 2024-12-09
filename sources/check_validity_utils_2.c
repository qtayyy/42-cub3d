/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:49:26 by nchok             #+#    #+#             */
/*   Updated: 2024/12/09 17:38:42 by nchok            ###   ########.fr       */
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

void	print_map(char **map)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			printf("%c", map[height][width]);
			if (width == (int)ft_strlen(map[height]) - 1)
				printf("\n");
			if (map[height][width] == '\0')
				printf("t");
			width++;
		}
		height++;
	}
	printf("\n");
}

int	flood_fill(char **map, int height)
{
	int		i;
	int		j;

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
		return;
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
