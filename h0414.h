//
// Created by 项雅丽 on 2020/2/1.
//

#ifndef LEETCODE_H0414_H
#define LEETCODE_H0414_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0414{
    class Solution {
    public:
        int thirdMax(vector<int> &nums) {
            int n = nums.size();

            long long first = LLONG_MIN;
            long long second = LLONG_MIN;
            long long third = LLONG_MIN;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] > first) {
                    third = second;
                    second = first;
                    first = nums[i];
                    cnt++;
                } else if (nums[i] == first) continue; // 需要把等于的情况单独拿出来，就是啥也不需要干的
                else if (nums[i] > second) {
                    third = second;
                    second = nums[i];
                    cnt++;
                } else if (nums[i] == second) continue;
                else if (nums[i] >= third) {
                    third = nums[i];
                    cnt++;
                }
            }

            if (third != LLONG_MIN) return third;
            else return first;
        }
    };
}

#endif //LEETCODE_H0414_H
