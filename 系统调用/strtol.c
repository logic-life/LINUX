#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
int main(int argc,char *argv[])
{
	if(argc<1){
		perror("输入错误");
		exit(1);
	}
       long int num=strtol(argv[1],NULL,8);
       if(num==LONG_MIN||num==LONG_MAX)
       {	
	       perror("进制转换错误");
	       exit(1);
       }
       printf("转换前的数为：%s,转换后的数为%ld\n",argv[0],num);


	return 0;
}
