/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:53:21 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/10 18:24:20 by hroxo            ###   ########.fr       */
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

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*out;

	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*ft_strncat(char *new, char *original, size_t nb)
{
	size_t	i;
	size_t	olen;
	char	*out;
	size_t	j;

	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	olen = ft_strlen(original);
	out = malloc(sizeof(char) * (olen + nb + 1));
	if (!out)
	{
		free(original);
		return (NULL);
	}
	while (original[i])
	{
		out[i] = original[i];
		i++;
	}
	while (new[j] && j < nb)
		out[i++] = new[j++];
	out[i] = 0;
	return (out);
}

int	has_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	len_to_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
