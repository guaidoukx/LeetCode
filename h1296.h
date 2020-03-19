//
// Created by 项雅丽 on 2020/2/19.
//

#ifndef LEETCODE_H1296_H
#define LEETCODE_H1296_H

#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

namespace h1296 {
    class Solution {
    public:
        bool isPossibleDivide(vector<int> &nums, int k) {
            int n = nums.size();
            if (n % k != 0) return false;
            unordered_map<int, int> m;
            set<int> s;
            priority_queue<int> q;
            for (int i = 0; i < n; i++) {
                m[nums[i]]++;
                s.insert(nums[i]);
            }
            for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
                q.push(*iter);
            }
            while (!q.empty()) {
                int num = q.top();
                q.pop();
                if (m[num] != 0) {
                    int tod = m[num];
                    for (int i = 0; i < k; i++) {
                        if (m[num - i] - tod < 0) return false;
                        else m[num - i] -= tod;
                    }
                }

            }
            return true;
        }
    };
}

#endif //LEETCODE_H1296_H
