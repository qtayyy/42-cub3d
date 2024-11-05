/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:01:41 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 13:00:09 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last = NULL;
	char		*token_start;

	if (str != NULL)
		last = str;
	if (last == NULL)
		return (NULL);
	while (*last && ft_strchr(delim, *last))
		last++;
	if (*last == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token_start = last;
	while (*last && !ft_strchr(delim, *last))
		last++;
	if (*last)
	{
		*last = '\0';
		last++;
	}
	else
		last = NULL;
	return (token_start);
}
