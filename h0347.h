//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0347_H
#define LEETCODE_H0347_H

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

namespace h0347 {
    class Solution {
    public:
        vector<int> topKFrequent(vector<int> &nums, int k) {
            vector<int> res;
            if (nums.size() == 0)
                return res;

            map<int, int> count;
            for (int i = 0; i < nums.size(); i++) {
                count[nums[i]]++;
            }
            // 要维护的是最小堆，新出现的比最小堆中的大的话，最小堆中的pop出去，新出现的push进去。
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            for (map<int, int>::iterator iter = count.begin(); iter != count.end(); iter++) {
                if (q.size() == k) {
                    if (iter->second > q.top().first) {
                        q.pop();
                        q.push(make_pair(iter->second, iter->first));
                    }
                } else {
                    q.push(make_pair(iter->second, iter->first));
                }
            }

            while (!q.empty()) {
                res.push_back(q.top().second);
                q.pop();
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0347_H
