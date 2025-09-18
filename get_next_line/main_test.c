/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:28:16 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/15 14:44:58 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

int	main(int argc, char **argv)
{
	int fd;
	int	i = 1;

	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)) != NULL && i < 5)
	{
		printf("%i %s", i, line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	printf("\nCHECKPOINT\n");
	free(line);
	close(fd);
	return (0);
}
