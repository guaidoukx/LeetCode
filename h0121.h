//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0121_H
#define LEETCODE_H0121_H

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

namespace h0121 {
    class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // int dp_i_0 = 0;
            // int dp_i_1 = INT_MIN;
            // for ( int i = 0; i<prices.size(); i++){
            //     dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            //     dp_i_1 = max(dp_i_1, 0 - prices[i]);
            // }
            // return dp_i_0;

            if (prices.size() == 0)
                return 0;
            int res = INT_MIN;
            int valley = INT_MAX;
            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < valley) {
                    valley = prices[i];
                }
                int tmp = prices[i] - valley;
                res = max(res, tmp);
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0121_H
