//
//  UnionFind.cpp
//  
//
//  Created by Jun Xiong on 4/17/15.
//
//

#include <stdio.h>
#include <vector>
#include "UnionFind.hpp"
#include <iostream>
using namespace std;

UnionFind::UnionFind(const int N):N_(N),id_(N),size_(N){
    for(int i=0;i<N_;i++){
        id_[i]=i;
        size_[i]=1;
      //  cout<<id_[i]<<" ";
    }
  //  cout<<endl;
}

UnionFind::~UnionFind(){

}

int UnionFind::root(int j){
    while(j!=id_[j]){
        j=id_[id_[j]];
    }
    return j;
}

bool UnionFind::connected(int i, int j){
    int ri=root(i),rj=root(j);
  //  cout<<i<<" "<<ri<<" "<<rj<<endl;
    return ri==rj;
}

void UnionFind::union1D(int i, int j){
    int ri=root(i),rj=root(j);
    if(ri!=rj){
        if(size_[ri]>size_[rj]){
            id_[rj]=ri;
            size_[ri]+=size_[rj];
            size_[rj]=size_[ri];
        }
        else {
            id_[ri]=rj;
            size_[rj]+=size_[ri];
            size_[ri]=size_[rj];
        }
    }
}

