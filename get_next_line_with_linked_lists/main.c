/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:52:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/21 09:55:55 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("read_error.txt", 0);
	char *text = get_next_line(fd);
	int i = 0;
	while (i < 6)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
		i++;
	}
	return 0;
}
