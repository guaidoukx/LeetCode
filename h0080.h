//
// Created by 项雅丽 on 2019/11/20.
//

#ifndef LEETCODE_H26_H
#define LEETCODE_H26_H

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

namespace h0080 {
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

#endif //LEETCODE_H26_H
