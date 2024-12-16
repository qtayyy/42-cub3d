/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:54:52 by qtay              #+#    #+#             */
/*   Updated: 2024/12/16 19:22:13 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	copy_cub_file(char *file_path, t_data *data)
{
	t_cubfile	*file_info;

	file_info = &data->file_info;
	if (get_file_rows(file_path, file_info))
		return (FAILURE);
	if (dup_cub_file(file_path, file_info))
		return (FAILURE);
	return (SUCCESS);
}

int	get_textures(t_data *data)
{
	char	*line;
	char	**temp_cubfile;

	temp_cubfile = data->file_info.cub_file;
	line = *temp_cubfile;
	while (line)
	{
		while (*line == '\t' || *line == ' ')
			line++;
		if (ft_isalpha(*line) && ft_isalpha(*(line + 1)))
			extract_dir_textures(line, &data->tex_info);
		else if (ft_isalpha(*line) && (*(line + 1) == ' '
				|| *(line + 1) == '\t'))
			extract_color_textures(line, &data->tex_info);
		temp_cubfile++;
		line = *temp_cubfile;
	}
	return (SUCCESS);
}

/**
 * Probably can check if nothing comes after the map here
 */
int	get_map(t_data *data)
{
	int		i;
	int		j;
	char	*line;
	char	**temp_cubfile;

	j = 0;
	data->map_rows = count_map_rows(data->file_info.cub_file);
	temp_cubfile = data->file_info.cub_file;
	line = *temp_cubfile;
	data->map = ft_calloc(data->map_rows + 1, sizeof(char *));
	if (data->map == NULL)
		return (err_msg("Malloc failure"), FAILURE);
	while (line)
	{
		i = 0;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]))
			data->map[j++] = dup_map(line);
		if (line[i] == '\0')
			break ;
		temp_cubfile++;
		line = *temp_cubfile;
	}
	return (SUCCESS);
}

int	get_file(char *file_path, t_data *data)
{
	if (copy_cub_file(file_path, data) == FAILURE)
		return (FAILURE);
	if (get_textures(data))
		return (err_msg("Texture error"), FAILURE);
	if (get_map(data) == FAILURE)
		return (err_msg("Map Eeror"), FAILURE);
	if (check_post_map(data) == FAILURE)
		return (err_msg("Unexpected content after map"), FAILURE);
	return (SUCCESS);
}
