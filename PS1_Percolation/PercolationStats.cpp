//
//  PercolationStats.cpp
//  
//
//  Created by Jun Xiong on 4/17/15.
//
//

#include "PercolationStats.hpp"
#include "Percolation.hpp"
#include <cmath>


PercolationStats::PercolationStats(int N, int T):N_(N), T_(T){
    int n_full, seed=0;
    double p;
    Percolation onePerco(N_, seed);
    for(int i=0;i<T_;i++){
        n_full=onePerco.onePercolation();
        p=((double)n_full)/(N_*N_);
        x_.push_back(p);
        seed++;
        onePerco.reInitialize(seed);
    }

}

PercolationStats::~PercolationStats(){
    
}

double PercolationStats::mean(){
    double sum=0;
    for(int i=0;i<T_;i++){
        sum+=x_[i];
    }
    return sum/T_;
}

double PercolationStats::stddev(){
    double sum_std=0, mean_x;
    mean_x=mean();
    for(int i=0; i<T_; i++){
        sum_std+=(x_[i]-mean_x)*(x_[i]-mean_x);
    }
    return sum_std/(T_-1);
}

double PercolationStats::confidenceLow(){
    double mean_x,std_x;
    mean_x = mean();
    std_x = stddev();
    return mean_x-1.96*std_x/sqrt(T_);
}

double PercolationStats::confidenceHigh(){
    double mean_x,std_x;
    mean_x = mean();
    std_x = stddev();
    return mean_x+1.96*std_x/sqrt(T_);
}
