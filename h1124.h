//
// Created by 项雅丽 on 2020/2/3.
//

#ifndef LEETCODE_H1124_H
#define LEETCODE_H1124_H

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace h1124{
    class Solution {
    public:
        int longestWPI(vector<int>& hours) {
            int n = hours.size();
            vector<int> preSum = vector<int>(n+1, 0);
            // preSum[i]-- preSum[n] 是针对 hours[0]--hours[n-1]
            for (int i = 1; i <= n; i++){
                if (hours[i-1] > 8)
                    preSum[i] = preSum[i-1] + 1;
                else
                    preSum[i] = preSum[i-1] - 1;
            }
            // for(int i = 0; i <= n; i++){
            //     cout<<preSum[i]<<" ";
            // }cout<<endl;

            int res = 0;
            stack<int> s;
            for (int i = 0; i <= n; i++){
                if (s.empty() || preSum[i] < preSum[s.top()]){
                    s.push(i);
                    // cout<<i << " ";
                }
            }

            for (int i = n ; i >= res; i --){ // 从后开始，已经换了下标了
                while(!s.empty() && preSum[i] > preSum[s.top()]){
                    res = max(res, i - s.top());
                    s.pop();
                }
            }
            return res;

        }
    };
}

#endif //LEETCODE_H1124_H
