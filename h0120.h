//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0120_H
#define LEETCODE_H0120_H

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

namespace h0120 {
    class Solution {
    public:
        int minimumTotal(vector<vector<int>> &triangle) {
            if (triangle.size() == 0) return 0;
            int n = triangle.size();
            vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i - 1][j - 1];
                }
            }
            int res = INT_MAX;
            for (int i = 0; i <= n; i++) {
                if (dp[n][i] < res)
                    res = dp[n][i];
            }
            return res;
        }

        // 自底向上的解法，用 O(n) 空间复杂度
        int minimumTotal1(vector<vector<int>> &triangle) {
            int n = triangle.size();
            if (n == 0) return 0;
            // 由于代表的是经过这个点会走过的路程，所以，初始化为0，因为还没经过，所以没有路程
            vector<int> dp(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                // 为什么是从 0-i呢，而不是从i-0呢，因为在判断更新的过程中，后面的数字是会被用来比较的，
                // 而考虑的，其实是上一层的情况，那么这个时候，这个值不能被改动，
                for (int j = 0; j <= i; j++)
                    dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

                for (int j = 0; j <= n; j++)
                    cout << dp[i] << " ";
                cout << endl;
            }
            return dp[0];
        }
    };
}

#endif //LEETCODE_H0120_H
