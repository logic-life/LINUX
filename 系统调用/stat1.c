#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("./a.out filename\n");
        exit(1);
    }
    struct stat st;
    //查询对应的文件信息
    int ret = stat(argv[1], &st);
    if (ret == -1)
    {
        perror("stat");
        exit(1);
    }
    //获取文件大小
    int size = (int)st.st_size;
    printf("file size =%d\n", size);

    return 0;
}