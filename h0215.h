//
// Created by 项雅丽 on 2019/11/20.
//

#ifndef LEETCODE_H0215_H
#define LEETCODE_H0215_H

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

namespace h0215 {
    class Solution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            sort(nums, k, 0, nums.size() - 1);
            return nums[k-1];
        }

        void sort(vector<int> &nums, int k, int l, int r) { // [l,r]
            if (r <= l)
                return;

            swap(nums[l], nums[rand() % (r - l + 1)+l]);
            int v = nums[l];
            int i, j = l;
            for (i = l + 1; i <= r; i++) {
                if (nums[i] > v) {
                    swap(nums[i], nums[j+1]);
                    j++;
                }
            }
            swap(nums[l], nums[j]);
            if (k > j)
                sort(nums, k, j + 1, r);
            else
                sort(nums, k, l, j-1);
        }
    };

}
#endif //LEETCODE_H0215_H
