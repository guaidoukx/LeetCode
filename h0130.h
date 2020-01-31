//
// Created by 项雅丽 on 2019/12/31.
//

#ifndef LEETCODE_H0130_H
#define LEETCODE_H0130_H

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

namespace h0130 {
    class Solution {
    public:
        vector<vector<bool >> marked;
        vector<vector<int>> direct = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n, m;
        void solve(vector<vector<char>> &board) {
            n = board.size();
            if (n==0)
                return;
            m = board[0].size();
            marked = vector<vector<bool >>(n , vector<bool>(m, false));
            for (int i=0;i<m;i++){
                getSolved(board, 0, i);
                getSolved(board, n-1, i);
            }
            for (int i=0;i<n;i++){
                getSolved(board, i, 0);
                getSolved(board, i, m-1);
            }

            for (int i=0;i<n;i++)
                for (int j=0; j<m; j++){
                    if (!marked[i][j])
                        board[i][j] = 'X';
                }
            return;
        }
        void getSolved(vector<vector<char>> &board, int r, int c){
            if (board[r][c]=='X')
                return;
            marked[r][c] = true;
            for (int i =0;i<4;i++){
                int nr = r+ direct[i][0];
                int nc = c + direct[i][1];
                if (0 <= nr && nr <n && 0<=nc && nc<m && !marked[nr][nc])
                    getSolved(board, nr, nc);
            }
        }
    };
}

#endif //LEETCODE_H0130_H
