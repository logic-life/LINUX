DIRS= sub add
FILES=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
OBJS= $(patsubst %.c,%.o,$(FILES))
# 指定静态库和主函数，链接
main: main.c liboperator.a
	$(CC) -g -o main main.c -L./ -loperator
# 静态库生成	
liboperator.a: $(OBJS)
	$(AR) rcs $@ $^
# 删除生成的库和目标文件
clean:main liboperator.a $(OBJS)
	-$(RM) $^
-PHONY: clean main #伪目标防止文件夹中的同名文件干扰指令执行
