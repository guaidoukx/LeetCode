//
// Created by 项雅丽 on 2020/1/13.
//

#ifndef LEETCODE_H0674_H
#define LEETCODE_H0674_H

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

namespace h0674 {
    class Solution {
    public:
        int findLengthOfLCIS(vector<int> &nums) {
            int n = nums.size();
            if (n == 0) return 0;

            int l = 0, r = 1, maxLength = 0, curLength = 1;
            while (r < n) {
                if (nums[r] > nums[r - 1]) {
                    cout << r << ' ';
                    r++;
                    curLength++;
                } else {
                    maxLength = max(maxLength, curLength);
                    cout << "maxLE" << maxLength;
                    l = r;
                    r = r + 1;
                    curLength = 1;
                }
            }
            maxLength = max(maxLength, curLength);
            return maxLength;
        }
    };
}

#endif //LEETCODE_H0674_H
