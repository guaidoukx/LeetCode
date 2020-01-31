//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0063_H
#define LEETCODE_H0063_H

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

namespace h0063 {
    class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
            int m = obstacleGrid.size();
            if (m == 0) return 0;
            int n = obstacleGrid[0].size();
            // 竟然还会有溢出的问题。。。
            vector<vector<long long>> dp = vector<vector<long long >>(m + 1, vector<long long >(n + 1, 0));
            dp[1][1] = obstacleGrid[0][0] == 0 ? 1 : 0;
            for (int i=1;i<=m;i++){
                for ( int j=1;j<=n;j++){
                    if (i==1 && j==1) continue;
                    if (obstacleGrid[i-1][j-1] == 0)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    else
                        dp[i][j] = 0;
                }
            }
            return dp[m][n];
        }
    };
}

#endif //LEETCODE_H0063_H
