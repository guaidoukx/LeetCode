//
// Created by 项雅丽 on 2020/1/30.
//

#ifndef LEETCODE_H0006_H
#define LEETCODE_H0006_H

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

namespace h006{
    class Solution {
    public:
        string convert(string s, int numRows) {
            string res = "";
            int n = s.size();
            if (n == 0 || numRows <= 0) return res;
            if (n == numRows || numRows == 1) return s;

            int gap = 2 * numRows - 2;
            for (int i = 0; i < numRows; i++) {
                int k = 0;
                if (i == 0 || i == numRows - 1) {
                    while (true) {
                        if (k * gap + i >= n) break;
                        res += s[k * gap + i];
                        k++;
                    }
                } else {
                    while (true) {
                        if (k * gap + i >= n) break;
                        res += s[k * gap + i];
                        if (k * gap + gap - i >= n) break;
                        res += s[k * gap + gap - i];
                        k++;
                    }
                }
            }

            return res;
        }
    };
}

#endif //LEETCODE_H0006_H
