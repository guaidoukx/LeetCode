//
// Created by 项雅丽 on 2020/2/8.
//

#ifndef LEETCODE_H0611_H
#define LEETCODE_H0611_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0611 {
    class Solution {
    private:
        void quicksort(vector<int> &nums, int l, int r) {
            if (l >= r) return;
            int k = rand() % (r - l + 1) + l;
            swap(nums[l], nums[k]);
            int v = nums[l];
            int j = l;
            for (int i = l + 1; i <= r; i++) {
                if (nums[i] < v) {
                    swap(nums[j + 1], nums[i]);
                    j++;
                }
            }
            swap(nums[l], nums[j]);
            quicksort(nums, l, j - 1);
            quicksort(nums, j + 1, r);
        }

    public:
        int triangleNumber(vector<int> &nums) {
            int n = nums.size();
            if (n < 3) return 0;
            quicksort(nums, 0, n - 1);

            int res = 0;
            for (int i = 0; i < n - 2; i++) {
                int l = i + 1;
                int r = i + 2;
                while (l < n - 1 && l < r) {
                    while (r < n && nums[i] + nums[l] > nums[r]) {
                        r++;
                    }
                    res += r - l - 1;
                    l++;
                    if (r <= l) r = l + 1;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0611_H
