//
//  MCPercolate.cpp
//  
//
//  Created by Jun Xiong on 4/17/15.
//
//

#include <stdio.h>
// #include "Percolation.hpp"
#include "PercolationStats.hpp"
#include <iostream>
using namespace std;

int main(){
    const int N=100, T=1000;
    PercolationStats PStat(N,T);
    //int n_full;
    //double p;
    double mean, sigma, confidLow, confidHigh;
  /*  Percolation onePerco(N, seed);
    n_full=onePerco.onePercolation();
    p=((double)n_full)/(N*N);
    cout<<"p="<<p<<endl;*/
    mean=PStat.mean();
    sigma=PStat.stddev();
    confidLow=PStat.confidenceLow();
    confidHigh=PStat.confidenceHigh();
    cout<<"mean \tsigma \tconfidenceLow \tconfidenceHigh"<<endl;
    cout<<mean<<"\t"<<sigma<<"\t"<<confidLow<<"\t"<<confidHigh<<endl;
    return 0;
}