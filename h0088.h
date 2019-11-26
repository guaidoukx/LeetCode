//
// Created by 项雅丽 on 2019/11/20.
//

#ifndef LEETCODE_H0088_H
#define LEETCODE_H0088_H

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

namespace h0088 {
    class Solution {
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

            for (int i = 0; i < n; i++) {
                nums1[m + i] = nums2[i];
            }

            sort(nums1.begin(), nums1.end());

        }
    };
}

#endif //LEETCODE_H0088_H
