//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0047_H
#define LEETCODE_H0047_H

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

namespace h0047 {
    class Solution {
    public:
        vector<vector<int>> res;

        vector<vector<int>> permuteUnique(vector<int> &nums) {
            vector<int> out;
            map<int, int> recordMap;
            for (int i = 0; i < nums.size(); i++) {
                recordMap[nums[i]]++;
            }
            getPermute(nums, recordMap, 0, out);
            return res;
        }

        void getPermute(vector<int> &nums, map<int, int> &recordMap, int index, vector<int> &out) {
            if (index == nums.size()) {
                res.push_back(out);
                return;
            }
            for (auto &record:recordMap) {
                if (record.second > 0) {
                    out.push_back(record.first);
                    record.second--;
                    getPermute(nums,recordMap, index + 1, out);
                    out.pop_back();
                    record.second++;
                }
            }
            return;
        }

    };
}

#endif //LEETCODE_H0047_H
