//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0343_H
#define LEETCODE_H0343_H

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

namespace h0343 {
    class Solution {
    public:
        int integerBreak(int n) {
            vector<int> dp = vector<int>(n + 1, 0);
            dp[2] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    dp[i] = max(j * max(i - j, dp[i - j]), dp[i]);
                }

            }
            return dp[n];
        }
    };
}

#endif //LEETCODE_H0343_H
