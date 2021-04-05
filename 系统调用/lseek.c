#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void){

	int fd=open("lseek.txt",O_RDWR|O_CREAT,0775);
	if(fd==-1)
	{	
		perror("can't create lseek");
		exit(1);
	}
	int ret=lseek(fd,0,SEEK_CUR);
	if(ret==-1){
		perror("fd can't seek");
	}
        int location=lseek(fd,2000,SEEK_END);
	printf("location=%d",location);
	//使用lseek()函数时，最后需要调用write()函数写入任意字符，完成写入操作
        write(fd,"a",1);
	close(fd);



return 0;
}

