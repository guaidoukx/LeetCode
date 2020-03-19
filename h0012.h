//
// Created by 项雅丽 on 2020/1/31.
//

#ifndef LEETCODE_H0012_H
#define LEETCODE_H0012_H

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

namespace h0012 {
    class Solution {
    private:
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string addString(string a, int times) {
            string res = "";
            for (int i = 0; i < times; i++)
                res += a;
            return res;
        }

    public:
        string intToRoman(int num) {
            if (num > 3999 || num < 1) return "";
            string res = "";
            for (int i = 0; i < 13; i++) {
                int times = num / value[i];
                res += addString(s[i], times);
                num = num % value[i];
            }
            return res;
        }
    };

    vector<vector<string>> ok (){
        return 2;
    }
}

#endif //LEETCODE_H0012_H
