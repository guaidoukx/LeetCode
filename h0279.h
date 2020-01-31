//
// Created by 项雅丽 on 2019/12/15.
//

#ifndef LEETCODE_H0279_H
#define LEETCODE_H0279_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0279 {
    class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp = vector<int>(n + 1, 0);
            for (int i = 0; i <= n; i++)
                dp[i] = i;

            // 比自己写的少了一重循环
            // 先针对每个数，看最少需要多少个数的和，因为以后经常用到。
            for (int i = 1; i <= n; i++) {
                for (int j = 1; i - j * j >= 0; j++) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
            return dp[n];
        }
    };
}

#endif //LEETCODE_H0279_H
