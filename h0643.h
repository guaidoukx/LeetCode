//
// Created by 项雅丽 on 2020/2/19.
//

#ifndef LEETCODE_H0643_H
#define LEETCODE_H0643_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0643 {
    class Solution {
    public:
        double findMaxAverage(vector<int> &nums, int k) {
            int n = nums.size();
            int l = 0, r = k;
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += nums[i];
            }

            int max = sum;
            while (r < n) {
                sum = sum + nums[r] - nums[l];
                if (sum > max) max = sum;
                l++;
                r++;
            }
            return double(max) / k;
        }
    };
}

#endif //LEETCODE_H0643_H
