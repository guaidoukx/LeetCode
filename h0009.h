//
// Created by 项雅丽 on 2020/3/3.
//

#ifndef LEETCODE_H0009_H
#define LEETCODE_H0009_H

#include <iostream>
using namespace std;

namespace h0009{
    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0  || (x!=0 && x%10==0 )) return false;
            int l = x, r= 0;
            while(l >= r ){
                r = 10 *r + l % 10;
                l = l / 10;
                if (l == r || l == r / 10) return true;
            }
            return false;
        }
    };
}

#endif //LEETCODE_H0009_H
