/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:54:52 by qtay              #+#    #+#             */
/*   Updated: 2024/12/09 18:55:56 by nchok            ###   ########.fr       */
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
			data->map[j++] = dup_map(line, &data->file_info.map_end_row);
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
		return (err_msg("Texture error"), FAILURE); // change error msg
	if (get_map(data) == FAILURE)
		return (err_msg("Map Error"), FAILURE);
	if (check_post_map(data) == FAILURE)
		return (err_msg("Unexpected content found after map"), FAILURE);
	return (SUCCESS);
}

int	check_post_map(t_data *data)
{
	char	**temp_cubfile;
	char	*line;
	int		i;

	temp_cubfile = data->file_info.cub_file;
	line = *temp_cubfile;
	i = 0;
	while (line)
	{
		printf("line: %s\n", line);
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]) && ft_strncmp(line, data->map[0], ft_strlen(data->map[0])) == 0)
		{
			temp_cubfile += data->file_info.map_end_row;
			if (*temp_cubfile == NULL)
				break ;
			line = *temp_cubfile;
			if (line != NULL && line[i] != '\0' && line[i] != '\n')
				return (FAILURE);
		}
		else
		{
			temp_cubfile++;
			line = *temp_cubfile;
		}
	}
	return (SUCCESS);
}
