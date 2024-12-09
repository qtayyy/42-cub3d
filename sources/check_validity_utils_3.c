/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:09 by nchok             #+#    #+#             */
/*   Updated: 2024/12/09 17:36:25 by nchok            ###   ########.fr       */
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
	
	max_w = ft_strlen(map[i]);
	if (i == 0 || i >= (max_h - 1) || j == 0 || j >= (max_w - 1))
		return (SUCCESS);
	if (map[i][j + 1] != '\0' && is_0_or_player(map[i][j + 1]) == TRUE)
		return (FAILURE);
	if (map[i][j - 1] != '\0' && is_0_or_player(map[i][j - 1]) == TRUE)
		return (FAILURE);
	if (map[i + 1][j] != '\0' && is_0_or_player(map[i + 1][j]) == TRUE)
		return (FAILURE);
	if (map[i - 1][j] != '\0' && is_0_or_player(map[i - 1][j]) == TRUE)
		return (FAILURE);
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
