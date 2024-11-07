/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:21:21 by qtay              #+#    #+#             */
/*   Updated: 2024/11/06 16:01:54 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map_closed(char **map, int rows)
{
	int	i;
	int	prev;
	int	cur;

	i = 0;
	prev = ft_strlen(map[0]);
	if (ft_strspn(map[0], "1") != prev
		|| ft_strspn(map[rows - 1], "1") != (int)ft_strlen(map[rows - 1]))
		return (FAILURE);
	while (++i < rows - 1)
	{
		cur = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][cur - 1] != '1')
			return (FAILURE);
		if (cur > prev
			&& ft_strspn(map[i] + prev - 1, "1") != cur - prev + 1)
			return (FAILURE);
		if (cur < prev
			&& ft_strspn(map[i - 1] + cur - 1, "1") != prev - cur + 1)
			return (FAILURE);
		prev = cur;
	}
	return (SUCCESS);
}

int	check_num_players(char **map)
{
	int	i;
	int	j;
	int	num_players;

	i = -1;
	num_players = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				num_players++;
			j++;
		}
	}
	if (num_players != 1)
		return (FAILURE);
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	if (data->map_rows < 3)
		return (err_msg("Map must contain at least 3 rows"), FAILURE);
	if (check_map_closed(data->map, data->map_rows) == FAILURE)
		return (err_msg("Map is not closed by walls!"), FAILURE);
	if (check_num_players(data->map) == FAILURE)
		return (err_msg("This is a single player game"), FAILURE);
	return (SUCCESS);
}
