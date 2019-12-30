//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0077_H
#define LEETCODE_H0077_H

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

namespace h0077 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;

        vector<vector<int>> combine(int n, int k) {
            getCombine(1, n, 0, k);
            return res;
        }

        void getCombine(int l, int r, int cnt, int k) {
            if (cnt == k) {
                res.push_back(out);
                return;
            }
            for (int i = l; i <= r; i++) {
                out.push_back(i);
                getCombine(i + 1, r, cnt + 1, k);
                out.pop_back();
            }

        }
    };
}

#endif //LEETCODE_H0077_H
