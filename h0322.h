//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0322_H
#define LEETCODE_H0322_H

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

namespace h0322 {

    class Solution {
    public:
        int coinChange(vector<int> &coins, int amount) {
            int n = coins.size();
            if (amount==0) return 0;
            if (amount < 0 || n == 0) return -1;
            vector<int>dp(amount + 1, amount+1);
            dp[0] =0;

            for (int j = 1; j <= amount; j++) {
                for (int coin:coins){
                    if ( j>=coin){
                        dp[j] = min(dp[j], dp[j-coin]+1);
                    }
                }
            }
            return dp[amount]>amount?-1:dp[amount];
        }
    };
}

#endif //LEETCODE_H0322_H
