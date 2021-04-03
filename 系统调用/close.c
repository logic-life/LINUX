#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int fd;
    for (int i = 0; fd >= 0; i++)
    {
        fd = open("text.txt", O_RDONLY);
        if (fd > 0)
            printf("fd:%d\n", fd);
        else
        {
            printf("error,can't open file\n");
            exit(0);
        }
        //close(fd);
    }
    return 0;
}
