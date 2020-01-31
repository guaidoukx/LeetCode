//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0309_H
#define LEETCODE_H0309_H

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

namespace h0309{
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n <= 1) return 0;
            int  dp_i_0 = 0, dp_i_1 = INT_MIN, pre=0;
            for( int i=0;i<n;i++){
                int tmp = dp_i_0;
                dp_i_0 =  max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, pre - prices[i]);pre = tmp;
            }
            return dp_i_0;
        }

    };
}

#endif //LEETCODE_H0309_H
