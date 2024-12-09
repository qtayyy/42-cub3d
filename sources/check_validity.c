/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:21:21 by qtay              #+#    #+#             */
/*   Updated: 2024/12/09 13:23:49 by qtay             ###   ########.fr       */
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
	// if (ft_strspn(map[0], "1") != prev
	// 	|| ft_strspn(map[rows - 1], "1") != (int)ft_strlen(map[rows - 1]))
	// 	return (FAILURE);
	while (++i < rows - 1)
	{
		cur = ft_strlen(map[i]);
		// if (map[i][0] != '1' || map[i][cur - 1] != '1')
		// 	return (FAILURE);
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
			else if (ft_strchr("NSEW", map[i][j])) // might not be necessary
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

int	check_textures(t_textures *tex_info)
{
	if (!tex_info->north || !tex_info->south || !tex_info->east || !tex_info->west)
		return (err_msg("Direction texture missing"), FAILURE);
	// check whether texture files end with .xpm
	if (check_file_open(tex_info->north) || check_file_open(tex_info->south)
		|| check_file_open(tex_info->east) || check_file_open(tex_info->west))
		return (FAILURE);
	if (check_rgb(tex_info->floor) || check_rgb(tex_info->ceiling))
		return (FAILURE);
	tex_info->hex_floor = convert_rgb_hex(tex_info->floor);
	tex_info->hex_ceiling = convert_rgb_hex(tex_info->ceiling);
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	if (data->map_rows < 3)
		return (err_msg("Map must contain at least 3 rows"), FAILURE);
	// flood fill check space
	// replace spaces in the map with 1 (get_file -> get_map -> dup_map)
	if (check_map_closed(data->map, data->map_rows) == FAILURE)
		return (err_msg("Map is not closed by walls!"), FAILURE);
	if (check_num_players(data->map) == FAILURE)
		return (err_msg("This is a single player game"), FAILURE);
	if (check_map_elements(data) == FAILURE)
		return (err_msg("Map should only contain 0, 1 and one of NSEW"), FAILURE);
	if (check_textures(&data->tex_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
