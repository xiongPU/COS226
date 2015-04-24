CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

all: UnionFind.o Percolation.o MCPercolate.o MCPercolate

UnionFind.o : UnionFind.cpp UnionFind.hpp
	${CC} ${CFLAGS} -c UnionFind.cpp

Percolation.o : Percolation.cpp Percolation.hpp UnionFind.hpp
	${CC} ${CFLAGS} -c Percolation.cpp

MCPercolate.o : MCPercolate.cpp Percolation.hpp
	${CC} ${CFLAGS} -c MCPercolate.cpp

MCPercolate : MCPercolate.o Percolation.o UnionFind.o
	${CC} ${CFLAGS} UnionFind.o Percolation.o MCPercolate.o ${LDFLAGS} -o MCPercolate

clean:
	rm -f *.o
