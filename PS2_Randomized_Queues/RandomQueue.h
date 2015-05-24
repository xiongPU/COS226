//
//  RandomQueue.h
//  HW2, declare the randomized queue class
//
//  Created by Jun Xiong on 5/12/15.
//
//

#ifndef __HW2__RandomQueue__
#define __HW2__RandomQueue__

#include <stdio.h>
//include "Dequeue.h"
#include <vector>
//class Node;
#include <random>
#include <ctime>
#include <functional>
#include <stdexcept>
using namespace std;


class Qexception:public exception{
private:
    string error_message;
public:
    Qexception(string str):error_message(str){
    }
    virtual const char* what() const throw (){
        return error_message.c_str();
    }
    
};

template <class Item>
class RandomQueue{
public:
    RandomQueue(int N);
    bool isEmpty();
    int size();
    void enqueue(Item item);
    Item dequeue();
    Item sample();
    void shuffleIterator();
    vector<int> iterator_;
    Item getItem(int iterator);
    ~RandomQueue();
private:
    int size_;  // size of the queue
    int N_;  // capacity of the array
    vector<Item *> itemAddress_;

    
};

//
//  RandomQueue.cpp
//  HW2
//
//  Created by Jun Xiong on 5/12/15.
//
//


template <class Item>
RandomQueue<Item>::RandomQueue(int N):iterator_(N),size_(0), N_(N),itemAddress_(N){
    for(int i=0;i<N_;i++){
        itemAddress_[i]=NULL;
        iterator_[i]=i;
    }
}

template <class Item>
bool RandomQueue<Item>::isEmpty(){
    if(size_==0) return true;
    else return false;
}

template <class Item>
int RandomQueue<Item>::size(){
    return size_;
}

template <class Item>
void RandomQueue<Item>::enqueue(Item item){
    if(typeid(Item *) == typeid(char *)){
        if(&item == NULL){
            throw Qexception("NullPointerException");
            //throw myerr;
        }
    }
    if(size_<N_-1){
        itemAddress_[size_]=new Item(item);
        //    *itemAddress[size_]=item;
        size_++;
    }
    else{
        N_=N_+(int)(N_/3.0)+1;
        itemAddress_.resize(N_, NULL);
        iterator_.resize(N_,0);
        itemAddress_[size_]=new Item(item);
        //    *itemAddress[size_]=item;
        size_++;
    }
}

template <class Item>
Item RandomQueue<Item>::dequeue(){
    if(size_==0){
        //throw "Try to get item from empty queue";
        throw Qexception("Try to get item from empty queue");
    }
    mt19937 eng(chrono::high_resolution_clock::now()
                .time_since_epoch().count()+1);
    uniform_int_distribution<int> unif(0, size_-1);
    int n=unif(eng);
    Item it=*itemAddress_[n];
    *itemAddress_[n]=*itemAddress_[size_-1];
    delete itemAddress_[size_-1];
    itemAddress_[size_-1]=NULL;
    size_--;
    if(size_<N_/3.0-1){
        N_=(int)(N_/3.0);
        itemAddress_.resize(N_);
        iterator_.resize(N_,0);
    }
    return it;
}

template <class Item>
Item RandomQueue<Item>::sample(){
    if(size_==0){
        throw Qexception("Try to get item from empty queue");
    }
    mt19937 eng(chrono::high_resolution_clock::now()
                .time_since_epoch().count()+1);
    uniform_int_distribution<int> unif(0, size_-1);
    int n=unif(eng);
    return *itemAddress_[n];
}

template <class Item>
void RandomQueue<Item>::shuffleIterator(){
    if(size_==0){
        throw Qexception("Try to shuffle iterator of empty queue");
    }
    int i,n, temp;
    mt19937 eng(chrono::high_resolution_clock::now()
                .time_since_epoch().count()+1);
    for(i=0; i<size_; i++){
        iterator_[i]=i;
    }
    for(i=1;i<size_;i++){
        uniform_int_distribution<int> unif(0, i);
        n=unif(eng);
        if(n!=i){
            temp=iterator_[i];
            iterator_[i]=iterator_[n];
            iterator_[n]=temp;
        }
        
    }
}

template <class Item>
Item RandomQueue<Item>::getItem(int iterator){
    return *itemAddress_[iterator];
}

template <class Item>
RandomQueue<Item>::~RandomQueue(){
    for(int i=0;i<size_;i++){
        delete itemAddress_[i];
    }
}





#endif /* defined(__HW2__RandomQueue__) */
