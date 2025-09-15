/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:34:07 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/15 12:52:24 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, size_t n)
{
	char	*output;
	size_t	i;
	size_t	j;

	output = malloc(n + 1);
	j = 0;
	i = 0;
	while (s1[i])
		output[j++] = s1[i++];
	i = 0;
	n -= j;
	while (i < n)
		output[j++] = s2[i++];
	output[j] = 0;
	free(s1);
	return (output);
}

char	*get_more_space(char *line, size_t *cap)
{
	char	*temp;
	size_t	i;
	size_t	current_cap;

	current_cap = *cap;
	current_cap *= 2;
	*cap = current_cap;
	i = 0;
	temp = malloc(current_cap);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	while (line[i])
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = 0;
	free(line);
	line = temp;
	return (line);
}

char	*get_text(int fd, size_t nb_of_bytes, size_t current_cap)
{
	int		f_r;
	char	*line;
	char	buf[BUF_SIZE];

	line = malloc((BUF_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	f_r = read(fd, buf, BUF_SIZE);
	while (f_r > 0)
	{
		if (nb_of_bytes + f_r >= current_cap)
		{
			line = get_more_space(line, &current_cap);
			if (!line)
				return (NULL);
		}
		line = ft_strjoin(line, buf, nb_of_bytes + f_r);
		if (!line)
			return (NULL);
		nb_of_bytes += f_r;
		f_r = read(fd, buf, BUF_SIZE);
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h> //TODO 

int main(int argc, char **argv)
{
	(void) argc;
	int fd = open(argv[1], O_RDONLY);
	char *line = get_text(fd, 0, BUF_SIZE + 1);
	printf("%s", line);
	free(line);
	return 0;

}
*/
