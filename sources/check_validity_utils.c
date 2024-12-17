/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:36 by qtay              #+#    #+#             */
/*   Updated: 2024/12/18 03:18:58 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_file(char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	if (ft_strncmp(file_path + len - 4, ".cub", 4) != 0)
		return (err_msg("Error: Not a .cub file"), FAILURE);
	return (SUCCESS);
}

int	check_file_open(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (printf("Direction texture: %s: %s\n", file_path,
				strerror(errno)), FAILURE);
	close(fd);
	return (SUCCESS);
}

int	check_rgb(int *rgb)
{
	if (rgb == NULL)
		return (FAILURE);
	while (*rgb)
	{
		if (*rgb < 0 || *rgb > 255)
			return (err_msg("RGB not within [0,255] range"), FAILURE);
		rgb++;
	}
	return (SUCCESS);
}

unsigned long	convert_rgb_hex(int *rgb)
{
	unsigned long	ret;
	int				r;
	int				g;
	int				b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	ret = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
	return (ret);
}

int	check_texture_ext(t_textures *tex_info)
{
	if (ft_strncmp(tex_info->north + ft_strlen(tex_info->north) - 4, ".xpm",
			4) != 0 || ft_strncmp(tex_info->south + ft_strlen(tex_info->south)
			- 4, ".xpm", 4) != 0 || ft_strncmp(tex_info->east
			+ ft_strlen(tex_info->east) - 4, ".xpm", 4) != 0
		|| ft_strncmp(tex_info->west + ft_strlen(tex_info->west) - 4, ".xpm",
			4) != 0)
		return (err_msg("Texture files must end with .xpm"), FAILURE);
	return (SUCCESS);
}
