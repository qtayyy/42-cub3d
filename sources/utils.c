/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:59:16 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 14:00:50 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_double_arr(void **double_arr)
{
	int	i;

	i = 0;
	if (double_arr == NULL)
		return ;
	while (double_arr[i])
		free(double_arr[i++]);
	free(double_arr);
}

void	err_msg(char *msg)
{
	printf("%s\n", msg);
}
