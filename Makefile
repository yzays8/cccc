CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

c4: $(OBJS)
	$(CC) -o c4 $(OBJS) $(LDFLAGS)

$(OBJS): c4.h

test: c4
	./test.sh

clean:
	rm -f c4 *.o *~ tmp*

.PHONY: test clean
