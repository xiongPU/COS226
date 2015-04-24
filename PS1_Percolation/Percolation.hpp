#include <vector>
#include "UnionFind.hpp"
using namespace std;

class Site;

class Percolation{
public:
    const int N_;
    int n_full_;
    Percolation(int N, int seed);
    ~Percolation();



    void open(int, int);
    bool isOpen(int, int);
    bool isFull(int, int);
    int numberOfOpenSites();
    bool percolates();
    void reInitialize(int);
    void step();
    int onePercolation();

private:
    vector<vector<bool> > grid_;
    int n_open_;
    bool top_, bottom_;
    void open_order();
    double seed_;
    UnionFind *UF_;
    vector<Site> open_queue_;
    void shuffleQueue();
    
};

