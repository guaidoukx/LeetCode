//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0090_H
#define LEETCODE_H0090_H

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

namespace h0090 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;

        vector<vector<int>> subsetsWithDup(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            for (int k=0;k<=nums.size();k++)
                getSubsets(nums,k, 0 );
            return res;
        }
        void getSubsets(vector<int> &nums, int k, int start){
            if(k==0){
                res.push_back(out);
                return;
            }
            for(int i=start;i<nums.size();i++){
                if (i>start && nums[i]==nums[i-1]) continue;
                out.push_back(nums[i]);
                getSubsets(nums, k-1, i+1);
                out.pop_back();
            }
        }
    };
}

#endif //LEETCODE_H0090_H
