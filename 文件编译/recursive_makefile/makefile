CFLAGS = -O2
TARGET = main
export OBJSDIR= ${shell pwd}/objs

$(TARGET):$(OBJSDIR)	main.o
	$(MAKE) -C add
	$(MAKE) -C sub
	$(CC) -o $(TARGET) $(OBJSDIR)/*.o
main.o:%.o:%.c
	$(CC) -c $< -o $(OBJSDIR)/$@ $(CFLAGS) -Iadd -Isub
$(OBJSDIR):
	mkdir -p $(OBJSDIR)
clean:
	-$(RM) $(TARGET) $(OBJSDIR)/*.o