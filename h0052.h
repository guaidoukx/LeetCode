//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0052_H
#define LEETCODE_H0052_H

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

namespace h0052 {
    class Solution {
    public:
        vector<bool> col;
        vector<bool> dia1;
        vector<bool> dia2;
        vector<int> row;
        int res;

        int totalNQueens(int n) {
            res = 0;
            col = vector<bool>(n, false);
            dia1 = vector<bool>(2 * n - 1, false);
            dia2 = vector<bool>(2 * n - 1, false);
            row = vector<int>(n, -1);
            getQueens(n, 0);
            return res;
        }

        void getQueens(int n, int i) {
            if (i == n) {
                res++;
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!col[j] && !dia1[i + j] && !dia2[j - i + n - 1]){
                    col[j] = true;
                    dia1[i+j] = true;
                    dia2[j-i + n-1] = true;
                    row[i] = j;
                    getQueens(n, i+1);
                    col[j] = false;
                    dia1[i+j] = false;
                    dia2[j-i + n-1] = false;

                }
            }
            return;
        }
    };
}

#endif //LEETCODE_H0052_H
