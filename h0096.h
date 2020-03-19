//
// Created by 项雅丽 on 2020/3/2.
//

#ifndef LEETCODE_H0096_H
#define LEETCODE_H0096_H

#include <iostream>
#include <vector>
using namespace std;

namespace h0096{
    class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n+1, 1);
            for (int i = 2; i <= n; i ++){
                // dp[n]以每个节点为顶点，左边可以形成的多少种排布，右边可以形成多少中排布。
                // 例如以下表示当节点个数为i时，左边没有节点，右边i-1个节点，依次计算左边1个节点，右边i-2个节点等
                int l = 0, r = i - 1;
                int tmp = 0;
                while(l < i){
                    tmp += dp[l] * dp[r];
                    l ++;
                    r --;
                }
                dp[i] = tmp;
            }
            return dp[n];
        }
    };
}

#endif //LEETCODE_H0096_H
