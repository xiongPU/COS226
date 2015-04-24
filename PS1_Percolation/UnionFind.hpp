//
//  UnionFind.hpp
//  
//
//  Created by Jun Xiong on 4/17/15.
//
//

#ifndef _UnionFind_hpp
#define _UnionFind_hpp
#include <vector>
using namespace std;

class UnionFind{
public:
    const int N_;
    UnionFind(const int);
    ~UnionFind();
    void union1D(int, int);
    bool connected(int, int);
    
private:
    vector<int> id_;
    vector<int> size_;
//    void find();
 //   void count();
    int root(int);
};


#endif
