//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0037_H
#define LEETCODE_H0037_H

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

namespace h0037 {

    class Solution {
        vector<vector<bool>> row;
        vector<vector<bool>> col;
        vector<vector<bool>> square;
        vector<vector<bool>> visited;

    public:
        void solveSudoku(vector<vector<char>> &board) {
            row = vector<vector<bool>>(9, vector<bool>(9, false));
            col = vector<vector<bool>>(9, vector<bool>(9, false));
            square = vector<vector<bool>>(9, vector<bool>(9, false));
            visited = vector<vector<bool>>(9, vector<bool>(9, false));
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        visited[i][j] = true;
                        row[i][board[i][j] - '1'] = true;
                        col[j][board[i][j] - '1'] = true;
                        square[3 * (i / 3) + j / 3][board[i][j] - '1'] = true;
                    }
                }
            }
            getSukou(board, 0);
        }

        bool getSukou(vector<vector<char>> &board, int index) {
            if (index == 81)
                return true;

            int i = index / 9;
            int j = index % 9;
            if (visited[i][j]) {
                return getSukou(board, index + 1);
            }

            for (int d = 0; d < 9; d++) {
                if (!row[i][d] && !col[j][d] && !square[3 * (i / 3) + j / 3][d]) {
                    board[i][j] = '1' + d;
                    visited[i][j] = true;
                    row[i][d] = true;
                    col[j][d] = true;
                    square[3 * (i / 3) + j / 3][d] = true;
                    if (getSukou(board, index + 1)) return true;
                    visited[i][j] = false;
                    row[i][d] = false;
                    col[j][d] = false;
                    square[3 * (i / 3) + j / 3][d] = false;
                }
            }
            return false;
        }
    };
}

#endif //LEETCODE_H0037_H
