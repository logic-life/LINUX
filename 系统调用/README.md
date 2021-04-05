# 操作函数
## open() 打开或者创建一个文件
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <sys/types.h>
#include <sys/stat.h> //或者将前面两个合并为 #include<unistd.h>
#include <fcntl.h>
```
> int open(const char *pathname,int flags);
+ **<font color=#8A2BE20>pathname 指定打开的文件</font>**
 
+ <font color=#8A2BE20>**flag 设置文件打开后允许的操作方式，可以设置为：** </font>
    - O_RDONLY (只读)
    - O_WRONLY (只写)
    - O_RDWR   (读写)
    - O_APPEND (对文件写操作追加到文件尾端)
    - O_CREAT  (文件不存在就创建，设置该选项时，第三个mode参数需要同时设定)
    - O_EXCL   (查看文件是否存在，同时指定O_CREAT,而文件已经存在，会返回错误。用这种方法可以安全打开一个文件)
    - O_TRUNC  (文件存在，就把文本截断)
    - O_NONBLOCK  (打开文件为非阻塞方式，不指定，默认为打开方式阻塞方式)
```
    fd=open("./dict.txt",O_RDONLY);
    printf("fd=%d\n", fd);
```
> int open(const char *pathname,int flags,mode_t mode)
+ **<font color=#8A2BE20>mode 表示打开文件的权限</font>**
    - 使用数字表示：4:R 2:W 1:X
    - 分别指定用户、组用户、其他用户
```
    int fd = 0;
    //rw-r--r--，打开方式为用户读写、组用户可写、其他用户可写
    fd = open("./text.txt", O_EXCL | O_CREAT, 0644); 
    printf("fd=%d\n", fd);
```
> int create(const char *pathname,mode_t mode);
+ 相当于open(pathname ,O_WRONLY|O_CREAT|O_TRUNC,mode)
+ 创建指定文件名的文件

<font color=#F4A460>**打开成功则会返回3，否则返回-1**</font>

[open](./open.c)
***********************************
## close() 关闭文件函数
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <unistd.h>
```
> int close(int fd);
+ close()函数关闭文本描述符，关闭以后此文件描述符不再指向任何文件，描述符可以再次使用

+ 函数调用成功返回0,有错误发生则会返回-1

+ 文件描述符的数量大小是有限制的，应该对打开的文件进行关闭，否则可能会因为文件描述符达到最大限制，没有文件描述符可以分配造成打开文件的失败

[close](./close.c)

## read()读取函数
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <unistd.h>
```
> ssize_t read(int fd,void *buf,size_t count);
+ 读取fd对应的文件的count字节
+ 将读取的字符放到buf中
+ count为0,read函数也为0，不执行任何操作
+ 如果count>SSIZE_MAX,结果未知，不要超过缓冲区的最大范围限制，否则会造成数组溢出
+ 读取成功返回读取的字节数，返回值为-1时表示读取失败

[read](./read.c)
## write()写文件函数
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <unistd.h>
```
> ssize_t write(int fd,const void *buf,size_t count);
+ 向文件描述符fd写入count指定数量的数据
+ buf为写入数据的指针
+ 返回写入成功的字符数，失败则返回-1
+ 如果在打开文件时，指定了O_APPEND，则每次写操作前，会将写操作的位置指向文件的结尾处
+ 写操作并不能保证数据成功的写入磁盘，通常是将数据写入缓冲区，在合适的时机将数据写入缓冲区

[write](./write.c)

## lseek()文件偏移函数
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <unistd.h>
```
> off_t lseek(int fd, off_t offset, int whence);
+ offset表示偏移的值(int)
+ whence 表示操作的模式，可以设置为：
    + SEEK_SET 偏移量相对于文件启示位置
    + SEEK_CUR 偏移量相对于文件偏移当前所指位置
    + SEEK_END 偏移量相对于文件结尾对应位置
+ 写入偏移量，需要在最后添加write

[lseek](./lseek.c)

## fstat()文件状态函数
<font color=#F4A460>**使用前需要添加：**</font>
```
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
```
> int stat(const char *pathname, struct stat *statbuf);

> int fstat(int fd, struct stat *statbuf);

> int lstat(const char *pathname, struct stat *statbuf);
+ stat为穿透指令，可以通过软链接追踪源文件的信息，lstat为非穿透指令，只追踪软链接的信息
+ pathname为文件路径
+ statbuf是一个结构体指针

|类型|名称|描述|
|----------|-------------|-----------------------------------------|
|dev_t     |  st_dev     |   ID of device containing file          |
|ino_t     |  st_ino     |   Inode number                          |
|mode_t    |  st_mode    |   File type and mode                    |
|nlink_t   |  st_nlink   |   Number of hard links                  |
|uid_t     |  st_uid     |   User ID of owner                      |
|gid_t     |  st_gid     |   Group ID of owner                     |
|dev_t     |  st_rdev    |   Device ID (if special file)           |
|off_t     |  st_size    |   Total size, in bytes                  |
|blksize_t |  st_blksize |   Block size for filesystem I/O         |
|blkcnt_t  |  st_blocks  |   Number of 512B blocks allocated       |  
[stat](./stat.c)

## strtol()字符转换函数
<font color=#F4A460>**使用前需添加:**</font>
```
#include <stdlib.h>
```
> long int strtol(const char *nptr, char **endptr, int base);

> long long int strtoll(const char *nptr, char **endptr, int base);

+ nptr为需要转换的字符串
+ base 为指定的进制
+ 字符串中如果包含0x、0X、0等前缀也会按照前缀的进制进行转换
+ endptr为指向字符串无法识别的位置的指针
[字符串转换为对应进制](./strtol.c)
## mmap()函数
