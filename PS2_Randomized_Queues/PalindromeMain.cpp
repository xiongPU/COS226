//
//  Palindrome.cpp
//  HW2, Palindrome, probably needs to use enum
// use Dequeue to judge whether a Palinder or not
//
//  Created by Jun Xiong on 5/14/15.
//
//

#include <stdio.h>
#include "PalindromeCheck.h"
#include <iostream>
//#include <stdexcept>
using namespace std;

int main(int argc, char *argv[]){
//    char A[]="AGCTGCT";
    //{'A','G','C','T','A','G','C','T'};
    
    bool result;
    char *A=argv[1];
    try{
        PalindromeCheck pl(A);
        result=pl.check();
    }
    catch(const char* str){
        cerr<<"\n"<<str<<endl;
        return 0;
    }
    cout<<result<<endl;
    return 0;
}