//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0017_H
#define LEETCODE_H0017_H

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

namespace h0017 {
    class Solution {
    public:
        vector<string> res;
        vector<string> letters = {
                " ",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
        };

        vector<string> letterCombinations(string digits) {
            if (digits.size() == 0)
                return res;
            findComb(digits, 0, "");
            return res;
        }

        void findComb(const string &digits, int index, const string &s) {
            if (index == digits.size()) {
                res.push_back(s);
                return;
            }
            string ls = letters[digits[index] - '0'];
            for (int i = 0; i < ls.size(); i++) {
                findComb(digits, index + 1, s + ls[i]);
            }
            return;
        }
    };
}

#endif //LEETCODE_H0017_H
