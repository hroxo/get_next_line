/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:00:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/20 15:22:50 by hroxo            ###   ########.fr       */
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

	if (!stash)
		stash = ft_calloc(1, 1);	
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf || !stash)
		return (NULL);
	f_r = 1;
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

char	*get_next_line(int fd)
{
	char	*stash[1024];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file()
}
