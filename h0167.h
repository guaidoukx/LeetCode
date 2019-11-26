//
// Created by 项雅丽 on 2019/11/21.
//

#ifndef LEETCODE_H0167_H
#define LEETCODE_H0167_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>

using namespace std;


namespace h0167 {
    class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {

            assert(numbers.size() >= 2);

            int i = 0, j = numbers.size() - 1;
            vector<int> res;
            while (i < j) {
                if (numbers[i] + numbers[j] < target) {
                    i++;
                } else if (numbers[i] + numbers[j] > target) {
                    j--;
                } else {
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                    break;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0167_H
