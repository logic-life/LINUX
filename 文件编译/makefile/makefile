CFLAGS = -Iadd -Isub -O2
DIRS = sub add .
#遍历文件名称中的.c文件
FILES= $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
OBJS=$(patsubst %.c,%.o,$(FILES))
TARGET = main
$(TARGET):$(OBJS)
	$(CC) -o $@ $^
clean:
	-$(RM) $(TARGET) $(OBJS)
-PHONY: clean TARGET