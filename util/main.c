/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:52:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/21 15:52:16 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("41_with_nl.txt", 0);
	char *text = get_next_line(fd);
	while (text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	free(text);
	close(fd);
	return 0;
}
