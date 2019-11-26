//
// Created by 项雅丽 on 2019/11/26.
//

#ifndef LEETCODE_H0438_H
#define LEETCODE_H0438_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0438 {
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> res;
            int pLen = p.size(), sLen = s.size();

            if (pLen > sLen)
                return res;

            int arrP[26] = {0}, arrS[26] = {0};
            for (char i : p)
                arrP[i - 'a']++;

            int l = 0; // [l,r)
            for (int i = 0; i < pLen - 1; i++) {
                arrS[s[i] - 'a']++;
            }

            while (l <= sLen - pLen) {
                arrS[s[l + pLen - 1] - 'a']++; //这句话不能放最后呀，放最后不能判断l++之后是不是越界。
                if (equals(arrP, arrS))
                    res.push_back(l);
                arrS[s[l] - 'a']--;
                l++;
            }
            return res;
        }

        bool equals(int *arrs, int *arrp) { // 这是一种蠢方法。
            for (int i = 0; i < 26; i++) {
                if (arrp[i] != arrs[i])
                    return false;
            }
            return true;
        }
    };
}

#endif //LEETCODE_H0438_H
