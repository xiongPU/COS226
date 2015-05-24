//
//  PalindromeCheck.h
//  HW2
//
//  Created by Jun Xiong on 5/22/15.
//
//

#ifndef __HW2__PalindromeCheck__
#define __HW2__PalindromeCheck__

#include <stdio.h>
#include <string>
#include <set>

using namespace std;

class PalindromeCheck{
public:
    PalindromeCheck(const char *);
    ~PalindromeCheck(){}
    bool check();
private:
    const char* str_;
    set<char> palindrome={'A','C','T','G'};
    set<char> palindrome_low={'a','c','t','g'};
    char getPairPartner(char x);
};
#endif /* defined(__HW2__PalindromeCheck__) */
