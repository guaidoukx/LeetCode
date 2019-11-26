//
// Created by 项雅丽 on 2019/11/20.
//

#ifndef LEETCODE_H26_H
#define LEETCODE_H26_H

#include <iostream>
#include <vector>
#include <map>
#include <set>

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

#endif //LEETCODE_H26_H
