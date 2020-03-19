//
// Created by 项雅丽 on 2020/3/19.
//

#ifndef LEETCODE_H0014_H
#define LEETCODE_H0014_H

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
#include <algorithm>

using namespace std;

namespace h0014 {
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            string res = "";
            if (strs.size() == 0) return res;
            if (strs.size() == 1) return strs[0];
            unsigned long minSize = INT_MAX;
            for (int i = 0; i < strs.size(); i++) {
                minSize = min(minSize, strs[i].size());
            }
            bool allSame = true;
            for (int j = 0; j < minSize; j++) {
                for (int i = 1; i < strs.size(); i++) {
                    if (strs[i][j] != strs[i - 1][j]) {
                        allSame = false;
                        break;
                    }
                }
                if (allSame) res += strs[0][j];
                else break;
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0014_H
