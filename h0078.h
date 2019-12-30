//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0078_H
#define LEETCODE_H0078_H

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

namespace h0078 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;

        vector<vector<int>> subsets(vector<int> &nums) {

            for (int k=0;k<=nums.size();k++){
                getSubsets(nums, k, 0);
            }
            return res;
        }

        void getSubsets(const vector<int> &nums, int k, int start){
            if  (k==0){
                res.push_back(out);
                return;
            }
            for(int i=start;i<nums.size();i++){
                out.push_back(nums[i]);
                getSubsets(nums, k-1, i+1);
                out.pop_back();
            }
            return;
        }
    };
}

#endif //LEETCODE_H0078_H
