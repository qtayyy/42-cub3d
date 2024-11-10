/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:00 by qtay              #+#    #+#             */
/*   Updated: 2024/11/08 23:21:57 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_screen_pixels(t_data *data)
{
	int	i;

	i = -1;
	if (data->screen_pixels != NULL)
		free_double_arr((void **)data->screen_pixels);
	data->screen_pixels = ft_calloc(WIN_HEIGHT + 1, sizeof(int *));
	if (data->screen_pixels == NULL)
	{
		printf("Failed to allocate memory for screen_pixels\n");
		exit(1); // Allocation failed, handle the error
	}
	while (++i < WIN_HEIGHT)
	{
		data->screen_pixels[i] = ft_calloc(WIN_WIDTH + 1, sizeof(int *));
		if (data->screen_pixels[i] == NULL)
		{
			printf("screen pixel[%d] init fail\n", i);
			exit(1); // Exit, or handle the memory cleanup and return gracefully
		}
	}
}

void	render_raycast(t_data *data)
{
	init_screen_pixels(data);
	init_ray(&data->ray);
}
