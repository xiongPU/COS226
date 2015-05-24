//
//  PalindromeCheck.cpp
//  HW2
//
//  Created by Jun Xiong on 5/22/15.
//
//

#include "PalindromeCheck.h"
#include "Dequeue.h"
#include <cctype>
#include <iostream>
using namespace std;

PalindromeCheck::PalindromeCheck(const char *str):str_(str){
    
}

char PalindromeCheck::getPairPartner(char x){
    switch (x) {
        case 'A':
            return 'T';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'G':
            return 'C';
    }
    return '\0';
}

bool PalindromeCheck::check(){
    Deque<char> dq;
    const char *pt=str_;
    char lt,pre,post;
    bool complement=true;

    while(*pt!='\0'){
        //cout<<*pt;
        lt=*pt;
        if(palindrome.find(lt)==palindrome.end() && palindrome_low.find(lt)==palindrome_low.end()){
            throw "Please only type in letters of A C T G";
        }
        if(palindrome_low.find(lt)!=palindrome_low.end()){
            lt=toupper(lt);
        }
        // so now lt in the set now
        dq.addLast(lt);
        pt++;
    }
    //cout<<"\n"<<dq.size()<<endl;
    while(dq.size()>1){
        //cout<<dq.size()<<endl;
        pre=dq.removeFirst();
        post=dq.removeLast();
        //cout<<pre<<"\t"<<post<<endl;
        if(pre!=getPairPartner(post))
            complement=false;
    }
    //cout<<complement<<endl;
    return complement;
}
