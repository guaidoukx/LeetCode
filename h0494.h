//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0494_H
#define LEETCODE_H0494_H

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

namespace h0494 {
    class Solution {
    public:
        int findTargetSumWays(vector<int> &nums, int S) {
            int n = nums.size();
            if (n == 0) return 0;
            vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
            dp[0][1000] = 1;
            dp[0][nums[0] + 1000] = 1;
            dp[0][-nums[0] + 1000] = 1;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= 2000; j++) {
                    if (j - nums[i] + 1000 >= 0 && j + nums[i] + 1000 <= 2000)
                        dp[i][j + 1000] = dp[i - 1][j - nums[i] + 1000] + dp[i - 1][j + nums[i] + 1000];
                    else if (j - nums[i] + 1000 < 0)
                        dp[i][j + 1000] = dp[i - 1][j + nums[i] + 1000];
                    else
                        dp[i][j + 1000] = dp[i - 1][j - nums[i] + 1000];
                }
            }
            return dp[n][S + 1000];
        }
    };
}

#endif //LEETCODE_H0494_H
