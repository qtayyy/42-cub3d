/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:14:51 by qtay              #+#    #+#             */
/*   Updated: 2024/11/06 14:28:10 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_num_delims(char *line, int delim)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == delim && *(line + 1))
			count++;
		line++;
	}
	return (count);
}

static void	dup_color_texture(char *line, int **tex_color)
{
	char	*token;
	int		num_delims;
	int		*temp_color;

	while (*line == '\t' || *line == ' ')
		line++;
	num_delims = count_num_delims(line, ',');
	if (num_delims != 2)
	{
		err_msg("Invalid RGB");
		return ;
	}
	*tex_color = ft_calloc(4, sizeof(int));
	temp_color = *tex_color;
	// // if (*tex_color == NULL)
	// // {
	// // 	strerror() // malloc error
	// // }
	token = ft_strtok(line, ",");
	while (token && *token != '\n')
	{
		*temp_color = ft_atoi(token);
		token = ft_strtok(NULL, ",");
		temp_color++;
	}
}

void	extract_color_textures(char *line, t_textures *tex_info)
{
	if (ft_strncmp(line, "F", 1) == 0)
		dup_color_texture(line + 1, &tex_info->floor);
	else if (ft_strncmp(line, "C", 1) == 0)
		dup_color_texture(line + 1, &tex_info->ceiling);
}
