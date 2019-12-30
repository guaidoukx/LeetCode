//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0039_H
#define LEETCODE_H0039_H

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

namespace h0039 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;

        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
            if (candidates.size() == 0)
                return res;
            getComSum(candidates, target, 0);
            return res;
        }

        void getComSum(vector<int> &candidates, int target, int l) {
            if (target<=0) {
                if (target==0)
                    res.push_back(out);
                return;
            }
            for (int i = l; i < candidates.size(); i++) {
                target -= candidates[i];
                out.push_back(candidates[i]);
                // 还是从i开始，但是sum已经不一样了，所以也是代表其中数据可以重复的方式。
                getComSum(candidates, target, i);
                target += candidates[i];
                out.pop_back();
            }
            return;
        }
    };
}

#endif //LEETCODE_H0039_H
