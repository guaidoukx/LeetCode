//
// Created by 项雅丽 on 2019/12/15.
//

#ifndef LEETCODE_H0127_H
#define LEETCODE_H0127_H

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

namespace h0127 {
    class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
            // wordList.push_back(endWord); // endWord也需要在wordlist中，那么就不需要额外加进去了。
            wordList.push_back(beginWord);
            map<string, vector<string>> adj;
            map<string, bool> visited;
            map<string, int> res;
            map<string, string> from;
            for (int i = 0; i < wordList.size(); i++) {
                visited[wordList[i]] = false;
                for (int j = i + 1; j < wordList.size(); j++) { // 构建邻接矩阵
                    if (isSimilar(wordList[i], wordList[j])) {
                        adj[wordList[i]].push_back(wordList[j]);
                        adj[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
            // bfs
            queue<string> q;
            q.push(beginWord);
            visited[beginWord] = true;
            res[beginWord] = 0;
            while (!q.empty()) {
                string front = q.front();
                q.pop();
                for (string s:adj[front]) {
                    if (!visited[s]) {
                        from[s] = front; // 为了记录输出
                        q.push(s);
                        visited[s] = true;
                        res[s] = res[front] + 1;
                    }
                }
            }
            return res[endWord];

        }

        bool isSimilar(string a, string b) {
            if (a == b || a.size() != b.size())
                return false;
            int cnt = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i])
                    cnt++;
                if (cnt > 1)
                    return false;
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0127_H
