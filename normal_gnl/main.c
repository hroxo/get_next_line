/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:46:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/10 18:21:52 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char	*text = get_next_line(fd);

	while (text != NULL)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	free(text);
	return 0;
}
