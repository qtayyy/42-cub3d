/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:54:52 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 17:04:39 by qtay             ###   ########.fr       */
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

int	get_file(char *file_path, t_data *data)
{
	if (copy_cub_file(file_path, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
