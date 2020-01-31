//
// Created by 项雅丽 on 2020/1/5.
//

#ifndef LEETCODE_FEISHU1_H
#define LEETCODE_FEISHU1_H

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

namespace Feishu1 {
    vector<string> findWords(string input, vector<string> wordList) {
        string map = "22233344455566677778889999";
        vector<string> res;
        int inputLength = input.size();
        for (string word:wordList) {
            int wordLength = word.size();
            if (wordLength != inputLength) continue;
            bool flag = true;
            for (int i = 0; i < wordLength; i++)
                if (map[word[i] - 'a'] != input[i]) {
                    flag = false;
                    break;
                }
            if (flag)
                res.push_back(word);
        }
        return res;
    }
}

#endif //LEETCODE_FEISHU1_H
