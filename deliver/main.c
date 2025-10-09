/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:12:10 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/09 12:48:06 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *text;

	text = get_next_line(fd);
	while (text != NULL)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	free(text);
	close(fd);
	return (0);
}
