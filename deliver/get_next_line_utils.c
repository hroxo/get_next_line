/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:03:06 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/08 23:22:36 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *new, char *original, size_t nb)
{
	char	*output;
	size_t	i;
	size_t	j;
	size_t	len;

	if (original[0] == 0)
		len = nb;
	else
		len = nb + ft_strlen(original);
	i = 0;
	j = 0;
	output = malloc(sizeof(char) * (len + 1));
	if (!output || !new)
	{
		free(original);
		return (NULL);
	}
	while (original[i])
	{
		output[i] = original[i];
		i++;
	}
	while (new[j] && j <= nb)
		output[i++] = new[j++];
	output[i] = 0;
	return (output);
}

size_t	len_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}
