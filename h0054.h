//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0054_H
#define LEETCODE_H0054_H

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

namespace h0054 {
    class Solution {
    public:
        vector<vector<int >> direction = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        vector<vector<bool>> visited;

        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            vector<int> res;
            int m = matrix.size();
            if (m == 0)
                return res;
            int n = matrix[0].size();
            visited = vector<vector<bool>>(m, vector<bool>(n, false));
            int i = 0, j = 0;
            int cnt = 0;
            while (true) {
                while (j < n && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    cnt ++;
                    if (cnt == m*n)
                        return res;
                    j++;
                }
                j--;
                while (i < m && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    cnt ++;
                    if (cnt == m*n)
                        return res;
                    i++;
                }
                i--;
                while (j >= 0 && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    cnt ++;
                    if (cnt == m*n)
                        return res;
                    j--;
                }
                j++;
                while (i >= 0 && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    cnt ++;
                    if (cnt == m*n)
                        return res;
                    i--;
                }
                i++;
            }

        }
    };

}

#endif //LEETCODE_H0054_H
