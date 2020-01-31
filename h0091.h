//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0091_H
#define LEETCODE_H0091_H

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

namespace h0091 {

    class Solution {
    public:
        int numDecodings(string s) {
            int n = s.size();
            if (n == 0 || s[0] == '0') return 0;
            vector<int> dp = vector<int>(n, 1);
            for (int i = 1; i < n; i++) {
                int num = stoi(s.substr(i - 1, 2));
                if (s[i] == '0'){
                    if (num==10 || num==20)
                        dp[i] = max(dp[i] - 1, 1);
                    else
                        return 0;
                }
                else {
                    if (num <= 26 && num > 10)
                        dp[i] = dp[i - 1] + 1;
                    else
                        dp[i] = dp[i - 1];
                }
            }
            return dp[n-1];
        }
    };
}

#endif //LEETCODE_H0091_H
