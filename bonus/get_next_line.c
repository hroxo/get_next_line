/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:36:59 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/21 14:38:53 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_n_free(char *str, char *buf)
{
	char	*out;

	out = ft_strjoin(str, buf);
	if (!out)
		return (free(str), NULL);
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
			free(buf);
			return (NULL);
		}
		buf[f_r] = 0;
		if (f_r == 0)
			break ;
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
	// if (new_stash[0] == 0)
	// 	return (free(new_stash), NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_calloc(sizeof(char), 1);
		if (!stash)
			return (NULL);
	}
	stash = read_file(stash, fd);
	if (!stash)
		return (NULL);
	line = get_the_line(stash);
	if (!line)
		return (NULL);
	stash = update_stash(stash);
	return (line);
}
