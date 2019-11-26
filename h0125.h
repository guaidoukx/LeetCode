//
// Created by 项雅丽 on 2019/11/21.
//

#ifndef LEETCODE_H0125_H
#define LEETCODE_H0125_H
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

namespace h0125 {
    class Solution {
    public:
        bool isPalindrome(string s) {
            int l = s.size();
            if (l<=1){
                return true;
            }
            int i= 0,j=s.size()-1;
            while (i<=j){
                if (isalnum(s[i])&&isalnum(s[j])&&tolower((s[i]))==tolower(s[j])){
                    i++,j--;
                } else if(!isalnum(s[i])){
                    i++;
                } else if (!isalnum(s[j])){
                    j--;
                } else{
                    return false;
                }
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0125_H
