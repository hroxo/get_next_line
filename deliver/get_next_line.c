/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:46:37 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/09 15:06:04 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*text_to_string(char *stash, int fd)
{
	char	buf[BUFFER_SIZE];
	int	f_r;

	f_r = read(fd, buf, BUFFER_SIZE);
	while (f_r > 0)
	{
		if (f_r < BUFFER_SIZE)
		{
			stash = ft_strncat(buf, stash, f_r);
			if (!stash)
				return (NULL);
			f_r = 0;
		}
		else 
		{
			stash = ft_strncat(buf, stash, BUFFER_SIZE);
			if (!stash)
				return (NULL);
			f_r = read(fd, buf, BUFFER_SIZE);
		}
	}
	return (stash);
}

char	**ft_split(char	*str)
{
	char	**output;
	int	i;
	int	k;
	int	w;

	k = 0;
	i = 0;
	output = malloc(sizeof(char *) * (count_str(str)));
	if (!output)
		return (NULL);
	while (str[i])
	{
		w = 0;
		while (str[i + w] && str[i + w] != '\n')
			w++;
		if (str[i + w] == '\n')
			w++;
		if (w > 0)
		{
			output[k] = ft_strndup(&str[i], w);
			if (!output[k])
			{
				free(str);
				free(output);
				return (NULL);
			}
			i += w;
		}
		else
			i++;
		k++;
	}
	output[k] = NULL;
	return (output);
}

char	*get_next_line(int fd)
{
	char	*stash;
	static int	i = 0;
	char	**grid;
	char	*line;

	if (fd < 0)
		return (NULL);
	stash = NULL;
	stash = text_to_string(stash, fd);
	if (!stash)
		return (NULL);
	grid = ft_split(stash);
	if (!grid)
	{
		free(stash);
		return (NULL);
	}
	line = ft_strndup(grid[i], ft_strlen(grid[i]));
	free(stash);
	free(grid);
	i++;
	return (line);
}
