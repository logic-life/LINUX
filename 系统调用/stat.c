#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    struct stat st;
    int size = open("text.txt", O_CREAT | O_RDWR, 0775);
    if (size == -1)
    {
        perror("open file error");
        exit(1);
    }
    if (stat("text.txt", &st) == -1)
    {
        perror("fail to get states of file");
        exit(1);
    }
    printf("包含此文件的设备ID:%ld\n", st.st_dev);
    printf("inode:%ld\n", st.st_ino);
    printf("mode:%d\n", st.st_mode);
    printf("此文件的硬连接数:%ld\n", st.st_nlink);
    printf("所有者ID:%d\n", st.st_uid);
    printf("所有者组ID:%d\n", st.st_gid);
    printf("设备ID:%ld\n", st.st_rdev);
    printf("文件大小:%ld\n", st.st_size);
    printf("此文件的所在文件系统块大小:%ld\n", st.st_blksize);
    printf("块设备大小:%ld\n", st.st_blocks);
    printf("文件最后操作时间:%ld\n", st.st_atime);
    printf("文件最后修改时间:%ld\n", st.st_mtime);
    printf("文件最后更改时间戳:%ld\n", st.st_ctime);
    return 0;
}