//
// Created by 项雅丽 on 2020/2/28.
//

#ifndef LEETCODE_H0048_H
#define LEETCODE_H0048_H

#include <iostream>
#include <vector>
using namespace std;

namespace h0048{
    class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            if (n <= 1) return;

            int l = 0, r = n-1;
            while(l < r){
                for (int i=1; l+i <= r; i++){
                    int tmp = matrix[l][i+l];
                    matrix[l][i+l] = matrix[r-i][l];
                    matrix[r-i][l] = matrix[r][r-i];
                    matrix[r][r-i] = matrix[i+l][r];
                    matrix[i+l][r] = tmp;
                }
                l++;r--;
            }
        }
    };
}

#endif //LEETCODE_H0048_H
