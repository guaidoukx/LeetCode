//
// Created by 项雅丽 on 2019/12/31.
//

#ifndef LEETCODE_H0200_H
#define LEETCODE_H0200_H

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

namespace h0200 {
    class Solution {
    public:
        vector<vector<int>> direct = {{-1, 0},{0,  1},{1,  0},{0,  -1},};
        vector<vector<bool>> marked;
        int cnt, cols, rows;

        int numIslands(vector<vector<char>> &grid) {
            rows = grid.size();
            if (rows == 0)
                return 0;
            cols = grid[0].size();
            marked = vector<vector<bool>>(rows, vector<bool>(cols, false));
            cnt = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '1' && !marked[i][j]) {
                        cnt++;
                        getIslandNums(grid, i, j);
                    }
                }
            }
            return cnt;

        }

        void getIslandNums(vector<vector<char>> &grid, int x, int y) {
            if (grid[x][y] == '0')
                return;
            marked[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + direct[i][0];
                int ny = y + direct[i][1];
                if (0 <= nx && nx < rows && 0 <= ny && ny < cols && !marked[nx][ny]) {
                    getIslandNums(grid, nx, ny);
                }
            }
            return;
        }
    };
}

#endif //LEETCODE_H0200_H
