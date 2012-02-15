
CC=g++
LDFLAGS=-lboost_regex

PROG_NAME=nlp-morpho
SRCS=							\
	nlp-morpho.cpp	\
	Rule.cpp				\
	lstr.cpp				
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
