/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:51:35 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 01:45:11 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_post_map(t_data *data)
{
	char	*line;
	char	**temp_cubfile;
	int		end_map;
	int		start_map;

	temp_cubfile = data->file_info.cub_file;
	start_map = 0;
	end_map = 0;
	*temp_cubfile += skip_to_map(temp_cubfile);
	while (*temp_cubfile)
	{
		line = *temp_cubfile;
		if (check_line_has_only_spaces(line))
			return (FAILURE);
		line += skip_empty_spaces(line);
		if (!start_map && line_has_only_digit_space(line))
			start_map = 1;
		if (start_map && !line_has_only_digit_space(line))
			end_map = 1;
		if (end_map && *line != '\n')
			return (FAILURE);
		temp_cubfile++;
	}
	return (SUCCESS);
}

int	check_line_has_only_spaces(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line))
			line++;
		else
			break ;
	}
	if (*line == '\0')
		return (1);
	return (0);
}

int	skip_empty_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	ft_is_whitespace_only(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
