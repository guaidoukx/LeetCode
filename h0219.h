//
// Created by 项雅丽 on 2019/12/4.
//

#ifndef LEETCODE_H0219_H
#define LEETCODE_H0219_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0219 {
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k) {
            map<int, int> m;
            for (int i = 0; i < nums.size(); i++) {
                if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
                    return true;
                else {
                    m[nums[i]] = i;
                }
            }
            return false;
        }
    };
}

#endif //LEETCODE_H0219_H
