/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:08:10 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/20 18:12:23 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("get_next_line_bonus.c", 0);
	char *text = get_next_line(fd);
	while (text != NULL)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	free(text);
	return 0;
}
