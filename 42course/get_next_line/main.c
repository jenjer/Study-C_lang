#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDWR);
    int i = 0;
    while (i < 10)
    {
        char *t = get_next_line(fd);
		if (t == 0)
			break;
		i++;
    }
}
