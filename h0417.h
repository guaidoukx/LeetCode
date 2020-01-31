//
// Created by 项雅丽 on 2019/12/31.
//

#ifndef LEETCODE_H0417_H
#define LEETCODE_H0417_H

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

namespace h0417 {
    class Solution {
    public:
        vector<vector<bool>> pacific;
        vector<vector<bool>> atlantic;
        vector<vector<int>> res;
        vector<vector<int>> direction = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};
        int n, m;

        vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
            n = matrix.size();
            if (n == 0)
                return res;
            m = matrix[0].size();
            pacific = vector<vector<bool>>(n, vector<bool>(m, false));
            atlantic = vector<vector<bool>>(n, vector<bool>(m, false));
            for (int i = n - 1; i >= 0; i--) {
                dfs(matrix, pacific, i, 0, INT_MIN);
                dfs(matrix, atlantic, i, m - 1,INT_MIN);
            }

            for (int j = 0; j < m; j++) {
                dfs(matrix, pacific, 0, j, INT_MIN);
                dfs(matrix, atlantic, n - 1, j, INT_MIN);
            }


            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (pacific[i][j] && atlantic[i][j])
                        res.push_back(vector<int>{i, j});

            return res;
        }


        void dfs(const vector<vector<int>> &matrix, vector<vector<bool >> &visited, int r, int c, int pre) {
            if (r < 0 || r >= n || c >= m || c < 0 || visited[r][c] || matrix[r][c]<pre ) return;
            visited[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                    dfs(matrix, visited, nr, nc, matrix[r][c]);
            }
        }
    };
}

#endif //LEETCODE_H0417_H
