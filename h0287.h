//
// Created by 项雅丽 on 2020/3/7.
//

#ifndef LEETCODE_H0287_H
#define LEETCODE_H0287_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0287 {
    class Solution {
    public:
        int findDuplicate(vector<int> &nums) {
            if (nums.size() <= 1) return 0;
            int l = 1, r = nums.size() - 1; // n = nums.size()-1
            while (l < r) {
                int mid = int((l + r) / 2);
                int cnt = 0;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] <= mid && nums[i] >= l) cnt++;
                }
                if (cnt <= mid - l + 1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        }
    };
}

#endif //LEETCODE_H0287_H
