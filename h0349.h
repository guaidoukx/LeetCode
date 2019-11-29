//
// Created by 项雅丽 on 2019/11/26.
//

#ifndef LEETCODE_H0349_H
#define LEETCODE_H0349_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0349{
    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set<int> set1(nums1.begin(), nums1.end());

            set<int> res;
            for (int i=0;i<nums2.size();i++){
                if (set1.find(nums2[i])!= set1.end())
                    res.insert(nums2[i]);
            }

            vector<int> ressult(res.begin(), res.end());
            return ressult;
        }
    };
}

#endif //LEETCODE_H0349_H
