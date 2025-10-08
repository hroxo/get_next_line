/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:46:37 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/08 23:17:48 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*text_to_string(char *stash, int fd)
{
	char	buf[BUF_SIZE];
	int	f_r;
	char	*temp;

	if (stash != NULL)
	 	return (stash);
	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = 0;
	f_r = read(fd, buf, BUF_SIZE);
	while (f_r > 0)
	{
		if (f_r < BUF_SIZE)
		{
			temp = ft_strncat(buf, stash, f_r);
			if (!stash)
				return (NULL);
			f_r = 0;
		}
		else 
		{
			temp = ft_strncat(buf, stash, BUF_SIZE);
			if (!stash)
				return (NULL);
			f_r = read(fd, buf, BUF_SIZE);
		}
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	i = 0;
	len = len_nl(stash);
	line = malloc(len + 2);
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

char	*update_me(char *stash)
{
	char	*new_stash;
	size_t	len;

	len = len_nl(stash);
	new_stash = ft_strncat("\0", &stash[len], ft_strlen(stash) - len);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static	char	*stash;
	char	*line;

	if (fd < 0)
		return (NULL);
	stash = NULL;
	stash = text_to_string(stash, fd);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (!line)
	{
		free(stash);
		return (line);
	}
	stash = update_me(stash);
	printf("%s", stash);
	if (!stash)
		return (NULL);
	return (line);
}
