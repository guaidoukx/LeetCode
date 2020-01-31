//
// Created by 项雅丽 on 2019/12/31.
//

#ifndef LEETCODE_H0051_H
#define LEETCODE_H0051_H

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

namespace h0051 {
    class Solution {
    public:
        vector<bool> col;
        vector<bool> dia1;
        vector<bool> dia2;
        vector<vector<string>> res;
        vector<int> row;

        vector<vector<string>> solveNQueens(int n) {
            res.clear();
            row = vector<int>(n, -1);
            col = vector<bool>(n, false);
            dia1 = vector<bool>(2 * n - 1, false);
            dia2 = vector<bool>(2 * n - 1, false);
            getQueens(n, 0);
            return res;
        }

        void getQueens(int n, int i) {
            if (i == n) {
                res.push_back(toString(row));
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!col[j] && !dia1[i + j] && !dia2[j - i + n - 1]) {
                    col[j] = true;
                    dia1[i + j] = true;
                    dia2[j - i + n - 1] = true;
                    row[i] = j;
                    getQueens(n, i + 1);
                    col[j] = false;
                    dia1[i + j] = false;
                    dia2[j - i + n - 1] = false;
                }
            }
            return;
        }

        vector<string> toString(vector<int> out) {
            vector<string> rowRes;
            int n = out.size();
            for (int i = 0; i < n; i++) {
                string rowString = "";
                for (int j = 0; j < n; j++) {
                    if (out[i] == j)
                        rowString += "Q";
                    else
                        rowString += ".";
                }
                rowRes.push_back(rowString);
            }
            return rowRes;
        }
    };
}

#endif //LEETCODE_H0051_H
