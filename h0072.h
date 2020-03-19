//
// Created by 项雅丽 on 2020/2/29.
//

#ifndef LEETCODE_H0072_H
#define LEETCODE_H0072_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0072 {
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();
            if (m == 0 || n == 0) return max(m, n);
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (int i = 0; i <= m; i++)
                dp[i][0] = i;
            for (int j = 0; j <= n; j++)
                dp[0][j] = j;

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        // 主要是这儿的考虑
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

                }
            }
            return dp[m][n];
        }
    };
}

#endif //LEETCODE_H0072_H
