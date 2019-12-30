//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0216_H
#define LEETCODE_H0216_H

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

namespace h0216{
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> out;
        vector<vector<int>> combinationSum3(int k, int n) {
            getCombinationSum3(k, n, 1);
        }
        void getCombinationSum3(int k, int n, int start){
            if (k==0){
                if (n==0)
                    res.push_back(out);
                return;
            }
            for (int i=start;i<=9;i++){
                out.push_back(i);
                getCombinationSum3(k-1, n-i, i+1);
                out.pop_back();

            }
        }
    };

}

#endif //LEETCODE_H0216_H
