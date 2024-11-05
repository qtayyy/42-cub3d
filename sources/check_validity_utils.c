/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:36 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 16:56:56 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_file(char *file_path)
{
	int		len;

	len = ft_strlen(file_path);
	if (ft_strncmp(file_path + len - 4, ".cub", 4) != 0)
		return (err_msg("Error: Not a .cub file"), FAILURE);
	return (SUCCESS);
}
