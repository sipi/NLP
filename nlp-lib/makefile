
CC=gcc
LDFLAGS=

PROG_NAME=libnlp.so
SRCS=nlplib.c	

INCLUDE_DIR=include

DEBUG=0
ifeq (${DEBUG},1)
	DEBUG_FLAGS=-W -Wall -ansi -pedantic -g
endif

CFLAGS= ${DEBUG_FLAGS} -I ${INCLUDE_DIR}


OBJS=${SRCS:.c=.o}

${PROG_NAME}: ${OBJS}
	${CC} -o $@ -shared ${OBJS} ${LDFLAGS} ${CFLAGS}

%.o: src/%.c
	${CC} -o $@ -c $< -fPIC ${CFLAGS}



install:
	cp include/nlplib.h /usr/include/
	cp libnlp.so /usr/lib/



mrproper:
	rm -rf *.o *~ ${PROG_NAME}

clean:
	rm -rf *.o
