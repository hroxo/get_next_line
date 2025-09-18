
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
	int n = 0;
	while (line != NULL && n < 3)
	{
		n++;
		printf("==>output<==\n");
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return 0;
}
