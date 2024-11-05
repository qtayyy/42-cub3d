/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:56:44 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 17:21:43 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_file_rows(char *file_path, t_cubfile *file_info)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (printf("Error opening file: %s\n", strerror(errno)));
	line = get_next_line(fd);
	while (line)
	{
		file_info->file_rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (printf("Error closing file: %s\n", strerror(errno)));
	return (SUCCESS);
}

int	dup_cub_file(char *file_path, t_cubfile *file_info)
{
	int		fd;
	char	*line;
	int		index;

	index = -1;
	file_info->cub_file = ft_calloc((file_info->file_rows + 1), sizeof(char *));
	if (file_info->cub_file == NULL)
		return (err_msg("Malloc failure"), FAILURE);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		free_double_arr((void **)file_info->cub_file);
		return (printf("Error opening file: %s\n", strerror(errno)));
	}
	line = get_next_line(fd);
	while (line)
	{
		file_info->cub_file[++index] = ft_strdup(line);
		if (file_info->cub_file[index] == NULL)
		{
			free_double_arr((void **)file_info->cub_file);
			free(line);
			return (err_msg("ft_strdup failure"), FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
	{
		free_double_arr((void **)file_info->cub_file);
		return (printf("Error closing file: %s\n", strerror(errno)));
	}
	return (SUCCESS);
}
