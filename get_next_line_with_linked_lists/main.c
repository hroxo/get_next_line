#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd);

static int ends_with_nl(const char *s)
{
    if (!s) return 0;
    size_t i = 0;
    while (s[i]) i++;
    return (i > 0 && s[i-1] == '\n');
}

int main(void)
{
    int   fd = open("test.txt", O_RDONLY);
    char *line;
    int   n = 0;

    if (fd < 0) {
        perror("open");
        return 1;
    }

    while (n < 3 && (line = get_next_line(fd)) != NULL)
    {
        n++;
        printf("==>output<==\n");
        printf("line: %s", line);
        if (!ends_with_nl(line))
            putchar('\n');           // garante quebra de linha p/ última sem '\n'
        free(line);
    }

    close(fd);
    return 0;
}
