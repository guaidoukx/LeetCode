//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0213_H
#define LEETCODE_H0213_H

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

namespace h0213 {
    class Solution {
    public:
        int rob(vector<int> &nums) {
            int n = nums.size();
            if (n == 0) return 0;
            // 为啥要加这句，因为后面把这个数组分开的时候，并不好分开，
            // 由于只有一个元素的时候，分开以后两个数组都为空了，那么这种情况就直接这里处理掉。
            if (n == 1) return nums[0];
            vector<int> a(nums.begin(), nums.end() - 1);
            vector<int> b(nums.begin() + 1, nums.end());
            return max(myRob(a), myRob(b));
        }

        int myRob(vector<int> &nums) {
            int n = nums.size();
            if (n == 0) return 0;
            vector<int> dp(n + 1, 0);
            dp[1] = nums[0];
            for (int i = 2; i <= n; i++)
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

            return dp[n];
        }
    };
}

#endif //LEETCODE_H0213_H
