#include "Percolation.hpp"
#include <iostream>
#include <new>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "UnionFind.hpp"
#include <iostream>
#include <functional>
#include <chrono>
#include <random>
using namespace std;

class Site{
public:
    int x, y;
};

Percolation::Percolation(int N, int seed):N_(N),open_queue_(N*N),grid_(N, vector<bool>(N, false)), seed_(seed){
    int i, j;
    for(i=0;i<N_;i++){
        for(j=0;j<N_;j++){
            grid_[i][j]=false; //all sites are blocked at begining;
           // cout<<grid_[i][j]<<" ";
        }
      //  cout<<endl;
    }
    top_=true;
    bottom_=true;
    n_full_=0;
    shuffleQueue();
    UF_ = new UnionFind(N_*N_+2);
   // cout<<N_<<endl;

}

Percolation::~Percolation(){
    delete UF_;
}

bool Percolation::isOpen(int i, int j){
    if(grid_[i][j]){
        return true;
    }
    else return false;
}

int Percolation::numberOfOpenSites(){
/*int s=0;
    for(int i=0;i<N_;i++){
        for(int j=0;j<N_;j++){
            if(isOpen(i,j)) s++;
        }
    }
    return s;*/
    return n_full_;
}

void Percolation::shuffleQueue(){
    Site a;
    int n;
    mt19937 eng(chrono::high_resolution_clock::now()
                .time_since_epoch().count()+seed_);
    if ((int)open_queue_.size()!=N_*N_){
        cout<<"open_queue_ has a wrong size"<<endl;
    }
    else {
        for(int i=0;i<N_;i++){
            for(int j=0;j<N_;j++){
                open_queue_[i*N_+j].x=i;
                open_queue_[i*N_+j].y=j;
            }
            
        }
    }
   // srand(time(NULL)+seed_);
    for(int i=1;i<(int)open_queue_.size();i++){
        uniform_int_distribution<int> unif(0,i);
        n=unif(eng);
        if(n!=i){
            a=open_queue_[n];
            open_queue_[n]=open_queue_[i];
            open_queue_[i]=a;
        }
    }
}

void Percolation::open(int i, int j){
    int i_uf=i*N_+j+1;
    int left, up, right, down;
    grid_[i][j]=true;
    
    if(j>=1){
        left=i*N_+j;
        if(isOpen(i,j-1)){
            UF_->union1D(i_uf, left);
        }
    }
    
    if(j<=N_-2){
        right=i*N_+j+2;
        if(isOpen(i,j+1)){
            UF_->union1D(i_uf, right);
        }
    }
    
    if(i>=1){
        up=(i-1)*N_+j+1;
        if(isOpen(i-1,j)){
            UF_->union1D(i_uf, up);
        }
    }
    else{
        up = 0;
        UF_->union1D(i_uf, up);
    }
    
    if(i<=N_-2){
        down=(i+1)*N_+j+1;
        if(isOpen(i+1,j)){
            UF_->union1D(i_uf,down);
        }
    }
    else{
        down=N_*N_+1;
        UF_->union1D(i_uf,down);
    }
}

void Percolation::step(){
    int i, j, k;
    k=n_full_;
    i=open_queue_[k].x;
    j=open_queue_[k].y;
    open(i,j);
    n_full_++;
    //cout<<i<<" "<<j<<" "<<n_full_<<endl;
}

void Percolation::reInitialize(int seed){
    int i, j;
    for(i=0;i<N_;i++){
        for(j=0;j<N_;j++){
            grid_[i][j]=false; //all sites are blocked at begining;
        }
    }
    top_=true;
    bottom_=true;
    n_full_=0;
    seed_=seed;
    shuffleQueue();
    delete UF_;
    UF_ = new UnionFind(N_*N_+2);
}

bool Percolation::percolates(){
    return UF_->connected(0, N_*N_+1);
}

int Percolation::onePercolation(){
    if(n_full_>0){
        reInitialize(seed_);
    }
    for(int i;i<N_;i++){
        for(int j;j<N_;j++){
       //     cout<<grid_[i][j]<<endl;
        }
    }
    step();
    while(!percolates()){
        step();
    }
    return n_full_;
}

