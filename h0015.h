//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0015_H
#define LEETCODE_H0015_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

namespace h0015 {
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &nums) {


            // 解法1
            sort(nums.begin(), nums.end());
            int *arr = nums.data();

            vector<vector<int>> answer;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) break; // 1.缩小搜索空间
                if (i != 0 && nums[i] == nums[i - 1]) { // 2.缩小搜索空间
                    continue;
                }
                int l = i + 1, r = nums.size() - 1;
                while (r > l) {
                    if (nums[l] + nums[r] + nums[i] > 0)
                        r--;
                    else if (nums[l] + nums[r] + nums[i] < 0)
                        l++;
                    else {
                        while (l < r && nums[l] == nums[l + 1]) l++; // 和2等同的缩小搜索空间
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        vector<int> tmp = {nums[i], nums[l], nums[r]};
                        answer.push_back(tmp);
                        r--;
                        l++;
                    }
                }
            }
            return answer;
        }
    };
}

#endif //LEETCODE_H0015_H
