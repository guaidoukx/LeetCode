//
// Created by 项雅丽 on 2020/2/27.
//

#ifndef LEETCODE_H0022_H
#define LEETCODE_H0022_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0022 {
    class Solution {
    private:
        vector<string> res;

        void generate(string out, int l, int r) {
            if (l == 0 && r == 0) {
                res.push_back(out);
                return;
            }
            if (r < l || l < 0 || r < 0) {
                return;
            }
            generate(out + "(", l - 1, r);
            generate(out + ")", l, r - 1);
        }

    public:
        vector<string> generateParenthesis(int n) {
            generate("", n, n);
            return res;
        }
    };
}

#endif //LEETCODE_H0022_H
