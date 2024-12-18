/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_utils_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:53:50 by nchok             #+#    #+#             */
/*   Updated: 2024/12/18 16:57:20 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_me(int *i, int *j, int *row, int *col)
{
	if (*row == *i && *col == *j)
	{
		*col += 1;
		return (TRUE);
	}
	return (FALSE);
}
