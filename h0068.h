//
// Created by 项雅丽 on 2020/3/17.
//

#ifndef LEETCODE_H0068_H
#define LEETCODE_H0068_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0068 {
    class Solution {
    private:
        pair<int, string> getRow(vector<string> &words, int maxWidth, int l) {
            string row = "";
            if (l >= words.size()) return make_pair(l, row);
            row = words[l];
            int wordscnt = 1;
            int rowlen = words[l].size();
            int j;
            for (j = l + 1; j < words.size(); j++) {
                if (rowlen + 1 + words[j].size() <= maxWidth) {
                    wordscnt++;
                    rowlen = rowlen + 1 + words[j].size();
                } else
                    break;
            }
            cout << "aj: " << j << endl;
            if (j == words.size()) {
                for (int i = 1; i < wordscnt; i++) {
                    row += " ";
                    row += words[l + i];
                }
                while (row.size() < maxWidth)
                    row += " ";
            } else {
                if  (wordscnt == 1)
                    while(row.size() < maxWidth)
                        row += " ";
                else {
                    int spaceLen;
                    int toAddSpace;
                    // 剩余长度，分配给wordscnt-1个空间，原来就已经有一个空格了，space是最少每个空间的空格数
                    spaceLen = (maxWidth - rowlen) / (wordscnt - 1) + 1;
                    toAddSpace = (maxWidth - rowlen) % (wordscnt - 1);
                    string space = "";
                    for (int i = 0; i < spaceLen; i++)
                        space += " ";

                    for (int i = 1; i < wordscnt; i++) {
                        row += space;
                        if (toAddSpace > 0) {
                            row += " ";
                            toAddSpace--;
                        }
                        row += words[l + i];
                    }
                }
            }
            cout << j << endl;
            return make_pair(j, row);
        }

    public:
        vector<string> fullJustify(vector<string> &words, int maxWidth) {
            vector<string> res;
            if (words.size() == 0) return res;

            pair<int, string> p = getRow(words, maxWidth, 0);
            res.push_back(p.second);
            while (p.first < words.size()) {
                cout << "p.first: " << p.first << endl;
                p = getRow(words, maxWidth, p.first);
                res.push_back(p.second);
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0068_H
