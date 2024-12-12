/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:51:35 by nchok             #+#    #+#             */
/*   Updated: 2024/12/13 00:15:20 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_post_map(t_data *data)
{
	int		i;
	char	*line;
	char	**temp_cubfile;
	int		end_map;
	int		start_map;

	temp_cubfile = data->file_info.cub_file;
	start_map = 0;
	end_map = 0;
	i = 0;
	while (temp_cubfile[i])
	{
		line = temp_cubfile[i];
		if (!start_map && ft_isdigit(line[0]))
			start_map = 1;
		if (start_map && !ft_isdigit(line[0]))
			end_map = 1;
		if (end_map && line[0] != '\n')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
