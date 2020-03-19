//
// Created by 项雅丽 on 2020/2/3.
//

#ifndef LEETCODE_H0962_H
#define LEETCODE_H0962_H

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

namespace h0962 {
    class Solution {
    public:
        // 其实不是太懂，但是大概知道要用单调栈来解决，且并没有完整构建单调栈，只是从index 0 开始
        int maxWidthRamp(vector<int> &A) {
            int n = A.size();
            if (n == 0) return 0;

            stack<int> s;
            s.push(0);
            for (int i = 1; i < n; i++) {
                if (A[i] < A[s.top()])
                    s.push(i);
            }
            int res = 0;
            for (int i = n - 1; i >= res; i--) {
                while (!s.empty() && A[i] >= A[s.top()]) {
                    res = max(res, i - s.top());
                    s.pop();
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0962_H
