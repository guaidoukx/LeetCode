//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0079_H
#define LEETCODE_H0079_H

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

namespace h0079 {
    class Solution {
    public:
        vector<vector<bool>> visited;
        vector<vector<int>> direction = {{0,  1},
                                         {1,  0},
                                         {0,  -1},
                                         {-1, 0}};
        int n, m;

        bool exist(vector<vector<char>> &board, string word) {
            n = board.size();
            if (n == 0) return false;
            m = board[0].size();
            if (m * n < word.size()) return false;

            // 1. 初始化，为什么不用每次都初始化呢，因为但凡没找到，visited都会为false，不需要每次都初始化。
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == word[0])
                        if (findWord(board, word, i, j, 0)) return true;
                }
            }
            return false;
        }

        bool findWord(vector<vector<char>> &board, string word, int i, int j, int index) {
            if (index == word.size() - 1)
                return word[index] == board[i][j];

            // 2. 为什么这儿不需要visited[i][j] = true; 因为只要不能到达的，visited都会是false
            // 尽管在最后，有visited[i][j] = false，但是没执行到那一步呀，visited[i][j] = true以后，马上就结束本次函数了。
            // 另一个角度来理解什么是visited， visited[i][j] = true 代表就当前考虑来说，这个字母确实是在路径上的，
            // 两者都不相等，board[i][j]怎么会在单词里呢，所以visited[i][j] = false
            if (board[i][j] != word[index]) {
                return false;
            }

            visited[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + direction[k][0];
                int nj = j + direction[k][1];
                if (0 <= ni && ni < n && 0 <= nj && nj < m && !visited[ni][nj])
                    // 只要返回为true了，就可以直接一阶一阶返回了！但是是false的话，之后的还需要继续，所以 要先判断，才能返回。
                    if (findWord(board, word, ni, nj, index + 1)) return true;
            }
            visited[i][j] = false;
            return false;
        }
    };
}

#endif //LEETCODE_H0079_H
