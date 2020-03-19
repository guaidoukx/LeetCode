//
// Created by 项雅丽 on 2020/2/29.
//

#ifndef LEETCODE_H0056_H
#define LEETCODE_H0056_H

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

namespace h0065 {
    class Solution {
        struct cmp {
            bool operator()(vector<int> &a, vector<int> &b) {
                return a[0] > b[0];
            }
        };

    public:
        vector<vector<int>> merge(vector<vector<int>> &intervals) {
            vector<vector<int>> res;
            int n = intervals.size();
            if (n <= 1) return intervals;
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
            for (int i = 0; i < n; i++) {
                pq.push(intervals[i]);
            }
            while (!pq.empty()) {
                vector<int> tmp = pq.top();
                pq.pop();
                while (!pq.empty() && pq.top()[0] <= tmp[1]) {
                    tmp[1] = max(tmp[1], pq.top()[1]);
                    pq.pop();
                }
                res.push_back(tmp);
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0056_H
