//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0026_H
#define LEETCODE_H0026_H

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

namespace h0026{
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size()<2){
                return nums.size();
            }
            int pre=nums[0];
            int countRepeat = 0;
            for (int i =1;i<nums.size();i++){
                if (nums[i]==pre){
                    countRepeat ++;
                } else{
                    nums[i-countRepeat] = nums[i];
                    pre = nums[i];
                }
            }
            return nums.size() - countRepeat;

        }
    };
}

#endif //LEETCODE_H0026_H
