/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:51:35 by nchok             #+#    #+#             */
/*   Updated: 2024/12/12 23:17:07 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_post_map(t_data *data)
{
	int		i;
	char	*line;
	char	**temp_cubfile;

	i = get_index_to_end_map(data);
	if (i == 0)
		return (FAILURE);
	temp_cubfile = data->file_info.cub_file;
	while (temp_cubfile[i])
	{
		line = temp_cubfile[i];
		if (check_spaces_line(line) == FAILURE)
			return (FAILURE);
		if (check_line_has_content(line) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	get_index_to_end_map(t_data *data)
{
	int		i;
	int		j;
	char	*line;
	char	**temp_cubfile;

	i = 0;
	temp_cubfile = data->file_info.cub_file;
	while (temp_cubfile[i])
	{
		line = temp_cubfile[i];
		j = 0;
		while (line[j] == '\t' || line[j] == ' ')
			j++;
		if (ft_isdigit(line[j]))
		{
			i += data->map_rows;
			return (i);
		}
		i++;
	}
	return (0);
}

int	check_spaces_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (SUCCESS);
	}
	if (line[i] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int	check_line_has_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
