#class1 = RandomQueue.o
#UF = UnionFind.o
#STAT = PercolationStats.o
main = Subset.o
#objects = $(MC) $(STAT) $(Percolation) $(UF)
objects = $(main)
deps = RandomQueue.h
RM = rm
CXX=g++ -std=c++11
CXXFLAGS = -c -Wall

all: Subset $(objects)

Subset : $(objects)
	$(CXX) -o $@ $^

%.o: %.cpp $(deps)
	$(CXX) ${CXXFLAGS} -c -o $@ $<


#.PHONY: clean
clean:
	rm MCPercolate $(objects)

#-include .depend
