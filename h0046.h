//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0046_H
#define LEETCODE_H0046_H

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

namespace h0046 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<bool> used;

        vector<vector<int>> permute(vector<int> &nums) {
            vector<int> out;
            used = vector<bool>(nums.size(), false);
            getPermute(nums, 0, out);
            return res;
        }

        void getPermute(vector<int> &nums, int index, vector<int> &out) {
            if (index == nums.size()) {
                res.push_back(out);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    used[i] = true;
                    out.push_back(nums[i]);
                    getPermute(nums, index + 1, out);
                    out.pop_back();
                    used[i] = false;
                }
            }
            return;
        }
    };
}

#endif //LEETCODE_H0046_H
