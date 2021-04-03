#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    char buf[] = "quick brown fox jumps over the lazy dogs";
    char filename[] = "t1.txt";
    ssize_t size = -1;
    fd = open(filename, O_WRONLY);
    if (fd == -1)
        printf("Open file %s failure,fd:%d\n", filename, fd);
    else
        printf("Open fiel %s success,fd:%d\n", filename, fd);
    size = write(fd, buf, strlen(buf));
    printf("write %ld bytes to file %s\n", size, filename);
    close(fd);
    return 0;
}