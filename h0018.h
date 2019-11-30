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
            set<vector<int>> answer;
            if (nums.size()<4){
                vector<vector<int>> ans;
                return ans;
            }
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i]>0 && nums[i] > target) break; // 只有原本已经是正数了，还大于target，后面的搜索就不需要了。

                if (i + 4 < nums.size() && nums[i] == nums[i + 4])
                    // 虽然要减少搜索空间，一样的可能就不需要了，但是这个[0,0,0,0,1], 要给 4个数都是一样的 这种特例一点机会。
                    continue;

                for (int j = i + 1; j < nums.size()-2; j++) {
                    // 只有加起来已经是正数了，还大于target，后面的搜索就不需要了。
                    // 负数+负数 等于更小的 负数
                    if ((nums[i] + nums[j])>0 && (nums[i] + nums[j]) > target) break;

                    if (j + 3 < nums.size() && nums[j] == nums[j + 3]) // 同理，要给 3个数都是一样的 这种特例一点机会。
                        continue;

                    int l = j + 1, r = nums.size() - 1;
                    while (r > l) {
                        if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                            r--;
                        else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                            l++;
                        else{
                            while (r > l && nums[l] == nums[l + 1]) l++; // 为什么这两句不放在前面，因为只有等于了，改变其中的值才没关系
                            while (r > l && nums[r] == nums[r - 1]) r--; // [2,2,2,3] 这样会失去最后两个数为[2,2]的机会
                            vector<int> tmp={nums[i],nums[j],nums[l],nums[r]};
                            answer.insert(tmp);
                            l++;
                            r--;
                        }
                    }
                }
            }
            vector<vector<int>> ans(answer.begin(), answer.end());
            return ans;
        }
    };

}

#endif //LEETCODE_H0018_H
