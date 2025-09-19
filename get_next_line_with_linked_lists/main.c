#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return 0;
}
