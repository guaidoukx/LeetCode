//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0451_H
#define LEETCODE_H0451_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;

namespace h0451 {
    class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> dic;
            for (char c:s)
                dic[c]++;


            priority_queue<pair<int, char>> pairs;
            string res = "";
            for (unordered_map<char, int>::iterator iter = dic.begin(); iter != dic.end(); iter++) {
                pairs.push(make_pair(iter->second, iter->first));
            }

            while (!pairs.empty()){
                int times = pairs.top().first;
                char c = pairs.top().second;
                while (times){
                    res += c;
                    times --;
                }
                pairs.pop();
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0451_H
