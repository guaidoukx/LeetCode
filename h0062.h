//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0062_H
#define LEETCODE_H0062_H

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

namespace h0062{
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            if (m==0)
                return 0;
            vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 1));
            for ( int i=1;i<m;i++){
                for ( int j=1;j<n;j++){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
    };
}

#endif //LEETCODE_H0062_H
