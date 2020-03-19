//
// Created by 项雅丽 on 2020/3/11.
//

#ifndef LEETCODE_H1013_H
#define LEETCODE_H1013_H

#include <iostream>
#include <vector>
using namespace std;

namespace h1013{
    class Solution {
    public:
        bool canThreePartsEqualSum(vector<int>& A) {
            int n = A.size();
            if (n < 3) return false;
            int sum = 0;
            for (int i = 0; i< n; i++){
                sum += A[i];
            }
            if (sum / 3 * 3 != sum ) return false;
            int sum1 = 0;
            for ( int i = 0; i < n-2 ; i++){
                sum1 += A[i];
                if (sum1 == sum / 3){
                    int sum2 = 0;
                    for (int j = i+1; j < n-1; j++){
                        sum2 += A[j];
                        if (sum2 == sum /3) return true;
                    }
                }
            }return false;
        }
    };
}

#endif //LEETCODE_H1013_H
