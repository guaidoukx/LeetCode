//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0474_H
#define LEETCODE_H0474_H

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

namespace h0474 {
    class Solution {
    public:
        int findMaxForm(vector<string> &strs, int m, int n) {
            int k = strs.size();
            vector<vector<int>> dp0 (m+1, )
        }

        vector<int> countZerosAndOnes(string s){
            vector<int> res(2, 0);
            for ( int i=0;i<s.size();i++){
                 if (s[i] == '0')
                     res[0] ++;
                  else
                     res[1]++;
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0474_H
