
CC=g++
LDFLAGS=-lnlp -lsqlite3

PROG_NAME=nlp-tagger
SRCS=							\
	nlp-tagger.cpp	

INCLUDE_DIR=include

DEBUG=0
ifeq (${DEBUG},1)
	DEBUG_FLAGS=-W -Wall -ansi -pedantic -g
endif

CFLAGS=${DEBUG_FLAGS} -I ${INCLUDE_DIR}


OBJS=${SRCS:.cpp=.o}

${PROG_NAME}: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS} ${CFLAGS}

%.o: src/%.cpp
	${CC} -o $@ -c $< ${CFLAGS}


mrproper:
	rm -rf *.o *~ ${PROG_NAME}

clean:
	rm -rf *.o
