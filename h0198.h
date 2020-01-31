//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0198_H
#define LEETCODE_H0198_H

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

namespace h0198 {
    class Solution {
    public:
        int rob(vector<int> &nums) {
            int n = nums.size();
            if (n==0)
                return 0;
            vector<int> dp = vector<int> (n+1, 0);
            dp[1] = nums[0];
            for ( int i=2;i<=n;i++){
                dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
            }
            return dp[n];
        }
    };
}

#endif //LEETCODE_H0198_H
