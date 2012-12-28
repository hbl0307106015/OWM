TARGET = helper
OBJS = helper.o
CFLAGS =
LDFLAGS =

$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

helper.o:helper.c
	$(CC) $(CFLAGS) -c helper.c

.PHONY:clean
clean:
	-$(RM) -rf $(TARGET) $(OBJS) *~ 
