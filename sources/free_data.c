/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:07:15 by nchok             #+#    #+#             */
/*   Updated: 2024/12/13 20:15:25 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	if (data->map)
		free_double_arr((void **)data->map);
	if (data->textures)
		free_double_arr((void **)data->textures);
	if (data->screen_pixels)
		free_double_arr((void **)data->screen_pixels);
	free_texture(&data->tex_info);
	free_file_info(&data->file_info);
}

void	free_texture(t_textures *tex_info)
{
	if (tex_info->north)
		free(tex_info->north);
	if (tex_info->south)
		free(tex_info->south);
	if (tex_info->west)
		free(tex_info->west);
	if (tex_info->east)
		free(tex_info->east);
	if (tex_info->floor)
		free(tex_info->floor);
	if (tex_info->ceiling)
		free(tex_info->ceiling);
}

void	free_file_info(t_cubfile *file_info)
{
	if (file_info->cub_file)
		free_double_arr((void **)file_info->cub_file);
}