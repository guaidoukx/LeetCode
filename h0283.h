//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0283_H
#define LEETCODE_H0283_H

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

namespace h0283{
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int countZero = 0;
            for (int i=0;i<nums.size();i++){
                if (nums[i]==0){
                    countZero++;
                } else{
                    nums[i-countZero] = nums[i];
                }
            }
            while (countZero>0){
                nums[nums.size()-countZero]=0;
                countZero--;
            }
        }
    };
}

#endif //LEETCODE_H0283_H
