//
// Created by 项雅丽 on 2019/11/29.
//

#ifndef LEETCODE_H0202_H
#define LEETCODE_H0202_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <math.h>

using namespace std;

namespace h0202 {
    class Solution {
    public:
        bool isHappy(int n) {
            set<int> nums;
            while (n != 1){
                if (nums.find(n) != nums.end())
                    return false;
                nums.insert(n);
                n = square(n);
            }
            return true;
        }

        int square(int n) {
            int sq = 0;
            while (n  != 0) {
                sq += pow(n % 10, 2) ;
                n = n / 10;
            }
            return sq;
        }
    };

}

#endif //LEETCODE_H0202_H
