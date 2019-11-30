//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0205_H
#define LEETCODE_H0205_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0205{
    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if (s.size() != t.size())
                return false;

            map<char, char> map1, map2;
            for (int i=0;i<s.size();i++){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            for (int i=0;i<s.size();i++){
                if (map1[s[i]] != t[i]||map2[t[i]] != s[i])
                    return false;
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0205_H
