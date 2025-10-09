/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:03:06 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/09 13:38:10 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *new, char *original, size_t nb)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * (ft_strlen(new) + ft_strlen(original)));
	if (!out)
		return (NULL);
	if (original)
	{
		while (original[i])
		{
			out[i] = original[i];
			i++;
		}
	}
	while (new[j] && j < nb)
		out[i++] = new[j++];
	out[i] = 0;
	free(original);
	return (out);
}

char	*ft_strndup(char *str, int nb)
{
	char	*out;
	int	i;

	i = 0;
	out = malloc(sizeof(char) * (nb + 2));
	if (!out)
	{
		free(str);
		return (NULL);
	}
	if (nb > 0)
	{
		while (str[i] && str[i] != '\n')
		{
			out[i] = str[i];
			i++;
		}
	}
	out[i++] = '\n';
	out[i] = 0;
	printf("%s", out);
	return (out);
}

int	count_str(char *str)
{
	int	i;
	int	score;
	int	flag;

	flag = 0;
	score = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && flag == 0)
		{
			score++;
			flag = 1;
		}
		else
			flag = 0;	
		i++;
	}
	return (score + 1);
}
