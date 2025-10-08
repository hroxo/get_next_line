/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:12:10 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/08 22:53:52 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *text;
	int i = 0;

	text = get_next_line(fd);
	while (text != NULL && i < 3)
	{
		printf("%i\n", i);
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
		i++;
	}
	free(text);
	return (0);
}
