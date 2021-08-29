SRCS = $(wildcard *.c)
OBJS = $(SRCS:*.c=*.o)

all: ${OBJS}
	gcc $^ -o main
%.o: %.c
	gcc -c $^ -o $@

clean:
	rm main
 
