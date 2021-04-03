#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    // fd=open("./dict.txt",O_RDONLY);
    fd = open("./text.txt", O_RDWR | O_NONBLOCK, 0644); //rw-r--r--，打开方式为用户读写、组用户可写、其他用户可写
    printf("fd=%d\n", fd);
    close(fd);
    return 0;
}
