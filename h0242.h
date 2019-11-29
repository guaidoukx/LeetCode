//
// Created by 项雅丽 on 2019/11/28.
//

#ifndef LEETCODE_H0242_H
#define LEETCODE_H0242_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0242 {
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            int arrS[26] = {0}, arrT[26] = {0};
            for (char c:s)
                arrS[c - 'a']++;

            for (char c:t)
                arrT[c - 'a']++;

            for (int i = 0; i < 26; i++) {
                if (arrS[i] != arrT[i])
                    return false;
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0242_H
