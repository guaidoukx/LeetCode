//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0416_H
#define LEETCODE_H0416_H

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

namespace h0416 {
    class Solution {
    public:
        bool canPartition(vector<int> &nums) {
            int n= nums.size();
            if (n<=1) return false;
            int sum_ = 0;
            for (int i = 0; i < n; i++) {
                sum_ += nums[i];
            }
            int halfSum = sum_ / 2;
            if (halfSum * 2 != sum_ || halfSum == 0)
                return false;

            vector<vector<int>> dp(n+1, vector<int>(halfSum+1, 0));
            for (int i=1;i<=n;i++){
                for ( int j = 1;j<=halfSum;j++){
                    // 到i-1（主要是数组下标差异）这个数为止，刚好能凑到 和为j，那么就更新，不然dp[i][j]就为0
                    if (dp[i-1][j] == j )
                        dp[i][j] = j;
                    if ( j-nums[i-1]>=0 && dp[i-1][j-nums[i-1]] +  nums[i-1]==j)
                        dp[i][j] = j;
                }
            }
            if (dp[n][halfSum] == halfSum)
                return true;
            else
                return false;
        }
    };
}

#endif //LEETCODE_H0416_H
