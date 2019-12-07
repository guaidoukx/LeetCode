//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0020_H
#define LEETCODE_H0020_H

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

namespace h0020 {
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> sta;
            for (char c:s) {
                if (c == '[' || c == '{' || c == '(')
                    sta.push(c);
                else {
                    if (sta.size() == 0) return false;
                    char popChar = sta.top();
                    sta.pop();
                    if (popChar == '[' && c != ']') return false;
                    if (popChar == '{' && c != '}') return false;
                    if (popChar == '(' && c != ')') return false;
                }
            }
            if (!sta.empty()) return false;
            return true;
        }
    };
}

#endif //LEETCODE_H0020_H
