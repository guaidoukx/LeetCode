//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0018_H
#define LEETCODE_H0018_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0018 {

    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int> &nums, int target) {
            vector<vector<int>> ans;
            if (nums.size() < 4)
                return ans;

            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0 && nums[i] > target) break;// 只有原本已经是正数了，还大于target，后面的搜索就不需要了。

                if (i != 0 && nums[i] == nums[i - 1])  // 2.缩小搜索空间，第一次遇到先处理，后来有相同的再跳过
                    continue;

                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if ((nums[i] + nums[j]) > 0 && (nums[i] + nums[j]) > target) break;

                    if (j > i + 1 && nums[j] == nums[j - 1])
                        continue;

                    int l = j + 1, r = nums.size() - 1;
                    while (r > l) {
                        if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                            r--;
                        else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                            l++;
                        else {
                            while (r > l && nums[l] == nums[l + 1]) l++; // 为什么这两句不放在前面，因为只有等于了，改变其中的值才没关系
                            while (r > l && nums[r] == nums[r - 1]) r--; // [2,2,2,3] 这样会失去最后两个数为[2,2]的机会
                            vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                            ans.push_back(tmp);
                            l++;
                            r--;
                        }
                    }
                }
            }
            return ans;
        }
    };
}

#endif //LEETCODE_H0018_H
