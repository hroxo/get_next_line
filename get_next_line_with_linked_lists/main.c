
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd);

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	char	*line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	return 0;
}
