//
// Created by 项雅丽 on 2019/11/19.
//

#ifndef NOWCODER_27_H
#define NOWCODER_27_H

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
namespace h0027 {
    class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int countElements = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == val) {
                    countElements++;
                } else {
                    nums[i - countElements] = nums[i];
                }
            }
            return nums.size() - countElements;
        }
    };
}


#endif //NOWCODER_27_H
