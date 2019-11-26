//
// Created by 项雅丽 on 2019/11/21.
//

#ifndef LEETCODE_H0011_H
#define LEETCODE_H0011_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

namespace h0011 {
    class Solution {
    public:
        int maxArea(vector<int> &height) {
            int i = 0, j = height.size() - 1;
            int res = min(height[i], height[j])*(j-i);

            while (true) {
                if (i+1>=j)
                    break;
                if (min(height[i], height[j-1])<min(height[i+1],height[j])){
                    i++;
                } else
                    j--;
                res = max(res,min(height[i], height[j])*(j-i));
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0011_H
