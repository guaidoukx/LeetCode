//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0027_H
#define LEETCODE_H0027_H

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

namespace h0027{
    class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int countElements = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == val) {
                    countElements++;
                } else {
                    nums[i - countElements] = nums[i];
                }
            }
            return nums.size() - countElements;
        }
    };
}

#endif //LEETCODE_H0027_H
