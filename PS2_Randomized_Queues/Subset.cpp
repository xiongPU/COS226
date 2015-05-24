//
//  Subset.cpp
//  HW2
//
//  Created by Jun Xiong on 5/13/15.
//
//

#include <stdio.h>
#include "RandomQueue.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

char getRandomChar(){
    static unsigned seed= time(0);
    srand(seed);
    seed=rand();
    char c = 'A' + seed%26;
    return c;
}

int main(){
    //vector<string> str={"A", "B", "C", "D","E","F","G","H","I","J"};
    int N_c=100000, cycle=100;
    vector<string> str(N_c);
    RandomQueue<string> RQ(3);
    int k=1000,i,j;
    //char *ch=0;
    str[0]=getRandomChar();
    cout<<str[0]<<endl;
    for(j=1;j<=cycle;j++){
        for(i=0;i<N_c;i++){
           // *ch=getRandomChar();
           // str[i]=ch;
            //strcpy (str[i],ch);
            str[i]=getRandomChar();
            if(i%N_c==0){
               cout<<str[i]<<endl;
            }
        }
        for(i=0;i<str.size();i++){
            RQ.enqueue(str[i]);
        }
        if(j==cycle){
            for(i=0;i<str.size();i++){
                try{
                    RQ.dequeue();
                }
                catch (const char* error){  //directly catches the char* object
                    cerr<<"catch a string:"<<error<<endl;
                }
                catch (Qexception& error){
                    cerr<<error.what()<<endl;
                }
            }
        }
        cout<<j<<endl;
    }
    RQ.shuffleIterator();
    cout<<"The size of the queue is "<<RQ.size()<<endl;
    if(k>RQ.size()){
        cout<<"output number larger than item numbers"<<endl;
        return 0;
    }
    for(i=0; i<k;i++){
        cout<<RQ.getItem(RQ.iterator_[i])<<endl;
    }
    cout<<"see samples "<<endl;
    for(i=0; i<k;i++){
        cout<<RQ.sample()<<endl;
    }
    cout<<"Dequeue now"<<endl;
    for(i=0;i<k;i++){
        cout<<RQ.dequeue()<<endl;
    }
    cout<<RQ.size()<<endl;
    cout<<"Dequeue again to end"<<endl;
    try{
        for(i=0;i<N_c;i++){
            cout<<RQ.dequeue()<<"\t"<<RQ.size()<<endl;
        }
    }
    catch (const char* error){  //directly catches the char* object
        cerr<<"catch a string:"<<error<<endl;
    }
    catch (Qexception& error){
        cerr<<error.what()<<endl;
    }
    
    return 0;
}