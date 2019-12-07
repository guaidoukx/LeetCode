//
// Created by 项雅丽 on 2019/12/4.
//

#ifndef LEETCODE_H0217_H
#define LEETCODE_H0217_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0217{
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            if (nums.size()<=1)
                return false;

            map<int, int> map1;
            for (int i=0;i<nums.size();i++){
                if (map1[nums[i]]<1){
                    map1[nums[i]] ++;
                } else
                    return true;
            }
            return false;
        }
    };
}
// 其实都不需要看出现了几次，直接看有没有出现过就行了。直接用set就行。
#endif //LEETCODE_H0217_H
