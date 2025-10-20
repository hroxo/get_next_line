/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:00:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/20 18:24:34 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

char	*join_n_free(char *str, char *buf)
{
	char	*out;

	out = ft_strjoin(str, buf);
	if (!out)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	return (out);
}

char	*read_file(char *stash, int fd)
{
	char	*buf;
	int	f_r;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!stash)
		f_r = read(fd, stash, BUFFER_SIZE);
	}
	if (!buf || !stash)
		return (NULL);
	while (!has_nl(stash) && f_r > 0)
	{
		f_r = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = 0;
		if (f_r < 0)
		{
			free(buf);
			return (NULL);
		}
		stash = join_n_free(stash, buf);
	}
	free(buf);
	return (stash);
	
}

char	*get_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	if (stash[i])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_calloc(sizeof(char *), len + 2);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*update_stash(char *stash)
{
	size_t	nl_len;
	char	*new_stash;
	size_t	i;

	i = 0;
	nl_len = 0;
	while (stash[nl_len] && stash[nl_len] != '\n')
		nl_len++;
	new_stash = malloc(ft_strlen(stash) - nl_len);
	if (!new_stash)
		return (NULL);
	while (stash[nl_len])
		new_stash[i++] = stash[++nl_len];
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	if (!line)
	{
		clean_house(stash);
		return (NULL);
	}
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
