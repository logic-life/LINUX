CFLAGS = -Iadd -Isub -O2
DIRS = sub add .
FILES= $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
OBJS=$(patsubst %.c,%.o,$(FILES))
TARGET = main
$(TARGET):$(OBJS)
	$(CC) -o $@ $^
clean:
	-$(RM) $(TARGET) $(OBJS)