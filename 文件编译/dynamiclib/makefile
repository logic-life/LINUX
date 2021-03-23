DIRS = add sub	#子文件夹目录
FILES=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c ))
OBJS=$(patsubst %.c,%.o,$(FILES))
# 动态库地址
LIBS= -L./ -loperator -Wl,-rpath=/root/local/lib
main: main.c liboperator.so
	$(CC) -g -W main.c -o main $(LIBS)
	sudo cp liboperator.so /root/local/lib/
# -fpic参数声明链接库的代码段是可以共享的
# -shared参数声明编译为共享库
# 编辑的共享库为liboperator.so
liboperator.so: $(OBJS)
	$(CC) -g -W -shared -fpic -o $@ $^
clean:main liboperator.so $(OBJS) 
	-$(RM) $^
-PHONY:clean main
