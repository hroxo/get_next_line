/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:23 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/12 11:55:56 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_line(char *output, int fd)
{
	char    buf[BUFFER_SIZE + 1];
	int     f_r;

	f_r = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = 0;
	if (!output)
		output = ft_strdup(buf);
	else
		output = ft_strncat(buf, output, f_r);
	if (!output)
		return (NULL);
	while (!has_nl(output) && f_r > 0)
	{
		f_r = read(fd, buf, BUFFER_SIZE);
		output = ft_strncat(buf, output, f_r);
		if (!output)
			return (NULL);
	}
	return (output);
}

char    *extract_line(char *stash)
{
	size_t  len;
	size_t  i;
	char    *line;

	i = 0;
	len = len_to_nl(stash);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char    *clean_stash(char *str)
{
	char    *out;
	size_t  size_to_nl;
	size_t  len;
	size_t  i;

	i = 0;
	size_to_nl = len_to_nl(str);
	len = ft_strlen(str);
	if (len + size_to_nl == 0)
	{
		return (NULL);
	}
	out = malloc(sizeof(char) * ((len - size_to_nl)));
	if (!out)
	{
		free(str);
		return (NULL);
	}
	size_to_nl++;
	while (str[size_to_nl])
		out[i++] = str[size_to_nl++];
	out[i] = 0;
	return (out);
}

char    *get_next_line(int fd)
{
	static char     *stash = NULL;
	char    *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_line(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = clean_stash(stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	return (line);
}
