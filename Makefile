.PHONY = all clean

CC = gcc
CFLAGS = -lX11

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

%: %.o
	${CC} ${LINKERFLAG} $< -o $@

%.o: %.c
	${CC} -c $<

clean:
	rm -rvf *.o ${BINS}
