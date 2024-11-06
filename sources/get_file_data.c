/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:54:52 by qtay              #+#    #+#             */
/*   Updated: 2024/11/06 09:45:24 by qtay             ###   ########.fr       */
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

int	get_file(char *file_path, t_data *data)
{
	if (copy_cub_file(file_path, data) == FAILURE)
		return (FAILURE);
	if (get_textures(data))
		return (err_msg("Texture error"), FAILURE); // change error msg
	return (SUCCESS);
}
