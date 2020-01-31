//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0080_H
#define LEETCODE_H0080_H

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

namespace h0080{
    class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            if (nums.size() < 2)
                return nums.size();

            int pre = nums[0];
            int totalRepeat = 0;
            int elementTimes = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == pre) {
                    elementTimes += 1;
                    if (elementTimes >= 2)
                        totalRepeat++;
                } else {
                    pre = nums[i];
                    elementTimes = 0;
                }
                nums[i - totalRepeat] = nums[i];
            }
            return nums.size() - totalRepeat;
        }
    };
}

#endif //LEETCODE_H0080_H
