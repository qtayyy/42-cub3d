/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:18:06 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 01:50:31 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	line_has_only_digit_space(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line) || *line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	skip_to_map(char **temp_cubfile)
{
	int		i;

	i = 0;
	while (*temp_cubfile)
	{
		if (line_has_only_digit_space(*temp_cubfile))
			return (i);
		i++;
		temp_cubfile++;
	}
	return (0);
}
