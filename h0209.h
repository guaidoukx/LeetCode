//
// Created by 项雅丽 on 2019/11/25.
//

#ifndef LEETCODE_H0209_H
#define LEETCODE_H0209_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

namespace h0209 {
    class Solution {
    public:
        int minSubArrayLen(int s, vector<int> &nums) {
            if (nums.empty() || accumulate(nums.begin(),nums.end(),0)<s)
                return 0;

            int res = nums.size();
            int l = 0, r = -1, sums = 0;
            while (l < nums.size()) {
                if (sums < s && r < (int)nums.size()-1) {
                    r++;
                    sums+=nums[r];
                } else if (sums < s && r == (int)nums.size()-1){
                    break;
                }
                else{
                    res = min(res, r-l+1);
                    sums -= nums[l];
                    l++;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0209_H
