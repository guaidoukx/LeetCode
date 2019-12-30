//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0131_H
#define LEETCODE_H0131_H

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

namespace h0131 {
    class Solution {
    public:
        vector<vector<string>> res;

        vector<vector<string>> partition(string s) {
            vector<string> out;
            findPartition(s, 0, out);
            return res;
        }

        void findPartition(const string &s, int index, vector<string> &out) {
            if (index == s.size()) {
                res.push_back(out);
                return;
            }
            // 空字符串不会出现，在这里约束了。
            for (int n = 1; n <= (s.size() - index); n++) {
                string tmp = s.substr(index, n);
                // 不是回文不能break，因为后面还可能会回文呀！ "efe"
                if (isPalindrome(tmp)) {
                    out.push_back(tmp);
                    findPartition(s, index + n, out);
                    out.pop_back();
                }
            }
            return;
        }

        bool isPalindrome(string s) {
            if (s.size() <= 1)return true;
            int l = 0, r = s.size() - 1;
            while (r > l) {
                if (s[r] != s[l]) return false;
                r--;
                l++;
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0131_H
