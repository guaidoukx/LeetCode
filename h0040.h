//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0040_H
#define LEETCODE_H0040_H

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

namespace h0040 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;
        vector<int> cand;

        vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
            this->cand = candidates;
            sort(cand.begin(), cand.end());
            getComSum2(target, 0);
            return res;
        }

        void getComSum2(int target, int l) {
            if (target <= 0) {
                if (target == 0)
                    res.push_back(out);
                return;
            }
            for (int i = l; i < cand.size(); i++) {
                // 这儿好像不需要有used这个来标记，因为每次都是从l开始的呀，不管前面有几个相同的数字，只是考虑本次的
                // 害，说的不太清楚
                if (i > l && cand[i] == cand[i - 1])
                    continue;

                out.push_back(cand[i]);
                getComSum2(target - cand[i], i + 1);
                out.pop_back();
            }
            return;
        }

    };
}

#endif //LEETCODE_H0040_H
