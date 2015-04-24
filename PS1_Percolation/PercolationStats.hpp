//
//  PercolationStats.h
//  
//
//  Created by Jun Xiong on 4/17/15.
//
//

#ifndef ____PercolationStats__
#define ____PercolationStats__

#include <stdio.h>
#include <vector>
using namespace std;

class PercolationStats{
public:
    PercolationStats(int N, int T);
    ~PercolationStats();
    double mean();
    double stddev();
    double confidenceLow();
    double confidenceHigh();

private:
    const int N_,T_;
    vector<double> x_;
};

#endif /* defined(____PercolationStats__) */
