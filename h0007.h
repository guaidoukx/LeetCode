//
// Created by 项雅丽 on 2020/2/25.
//

#ifndef LEETCODE_H0007_H
#define LEETCODE_H0007_H

#include <iostream>

using namespace std;

namespace h0007 {
    class Solution {
    public:
        int reverse(int x) {
            bool neg = false;
            long long y = x;
            if (y < 0) {
                neg = true;
                y = -y;
            }
            long long res = 0;
            while (y != 0) {
                int yu = y % 10;
                y = y / 10;
                res = res * 10 + yu;
                if ((!neg && res > INT_MAX) || (neg && -res < INT_MIN))
                    return 0;
            }
            if (neg)
                res = -res;
            return res;

        }
    };
}

#endif //LEETCODE_H0007_H
