//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0064_H
#define LEETCODE_H0064_H

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

namespace h0064 {
    class Solution {
    public:
        int minPathSum(vector<vector<int>> &grid) {
            int m = grid.size();
            if (m == 0)
                return 0;
            int n = grid[0].size();
            vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
            for (int j = 0; j <= n; j++)
                dp[0][j] = INT_MAX;
            for (int i = 0; i <= m; i++)
                dp[i][0] = INT_MAX;
            dp[1][1] = grid[0][0];
            for (int i=1;i<=m;i++){
                for (int j=1; j<=n; j++){
                    if (i==1&&j==1)
                        dp[i][j] = grid[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
                }
            }
            return dp[m][n];
        }
    };
}

#endif //LEETCODE_H0064_H
