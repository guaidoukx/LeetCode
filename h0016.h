//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0016_H
#define LEETCODE_H0016_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0016{
    class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            assert(nums.size() >= 3);

            sort(nums.begin(), nums.end());
            int dis = INT_MAX;
            int res = accumulate(nums.begin(), nums.begin() + 3, 0);
            for (int i = 0; i < nums.size(); i++) {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum > target) {
                        if (sum - target < dis) {
                            dis = sum - target;
                            res = sum;
                        }
                        r--;
                    } else if (sum < target) {
                        if (target - sum < dis) {
                            dis = target - sum;
                            res = sum;
                        }
                        l++;
                    } else
                        return target;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0016_H
