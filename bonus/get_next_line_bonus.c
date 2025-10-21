/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:00:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/21 16:43:54 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

char	*join_n_free(char *str, char *buf)
{
	char	*out;

	if (!buf[0])
		return (str);
	out = ft_strjoin(str, buf);
	if (!out)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (out);
}

char	*read_file(char *stash, int fd)
{
	char	*buf;
	int		f_r;

	f_r = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (!has_nl(stash) && f_r > 0)
	{
		f_r = read(fd, buf, BUFFER_SIZE);
		if (f_r < 0)
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		buf[f_r] = 0;
		stash = join_n_free(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_the_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = 0;
	if (!stash[i])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_calloc(sizeof(char), len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
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
	new_stash = malloc(ft_strlen(stash) - nl_len + 1);
	if (!new_stash)
		return (NULL);
	while (stash[nl_len])
		new_stash[i++] = stash[++nl_len];
	new_stash[i] = 0;
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = get_the_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = update_stash(stash[fd]);
	if (stash[fd][0] == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
