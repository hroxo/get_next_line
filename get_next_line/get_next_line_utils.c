/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:34:07 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/14 22:34:29 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

char	*ft_strdup(char *str, size_t cap)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(cap * sizeof(char));
	if (!output)
		return (NULL);
	while (str[i]) 
	{
		output[i] = str[i];
		i++;
	}
	return (output);
}

char	*get_next_line(int fd)
{
	size_t	i;
	int	f_r;
	size_t	current_cap;
	size_t	nb_of_bytes;
	char	*line;
	char	*temp;
	char	c;

	i = 0;
	line = malloc((BUF_SIZE + 2) * sizeof(char));
	if (!line)
		return (NULL);
	f_r = read(fd, &c, 1);
	line[i] = c;
	nb_of_bytes = f_r; 
	i++;
	current_cap = BUF_SIZE;
	while (c != '\n' && c != '\0' && f_r > 0)
	{
		if (nb_of_bytes >= current_cap)
		{
			current_cap *= 2;
			temp = ft_strdup(line, current_cap);
			if (!temp)
			{
				free(line);
				return (NULL);
			}
			free(line);
			line = temp;
		}
		f_r = read(fd, &c, 1);
		line[i] = c;
		nb_of_bytes += f_r; 
		i++;
	}
	if (f_r < 0) 
		return (NULL);
	line[i] = '\0';
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	(void) argc;
	int fd = open(argv[1], O_RDONLY);
	char *line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	return 0;

}
*/
