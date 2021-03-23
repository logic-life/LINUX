#通用makefile，更改POS对应文件夹位置即可(直接生成可执行文件)
POS= .
name=main
src=$(foreach pos,$(POS),$(wildcard $(pos)/*.c))
$(name):$(src)
	$(CC) $^ -o $@
clean:
	-$(RM) -rf $(name)
-PHONY:clean 


#通用makefile，更改POS对应文件夹位置即可(生成.o文件)
#POS= .
#name=main
#src=$(foreach pos,$(POS),$(wildcard $(pos)/*.c))
#target=$(patsubst %.c,%.o,$(src))
#$(name):$(target)
#       $(CC) $^ -o $@
#clean:
#        -$(RM) -rf $(target) $(name)
#-PHONY:clean 


