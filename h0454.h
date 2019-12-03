//
// Created by 项雅丽 on 2019/12/2.
//

#ifndef LEETCODE_H0454_H
#define LEETCODE_H0454_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0454{
    class Solution {
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int res = 0;
            if (A.size()==0 ||B.size()==0 ||C.size()==0 ||D.size()==0)
                return res;
            map<int, int> mapAB;
            map<int, int> mapCD;
            for(int i=0;i<A.size();i++){
                for(int j=0;j<B.size();j++){
                    mapAB[A[i]+B[j]] ++;
                }
            }
            for(int i=0;i<C.size();i++){
                for (int j=0;j<D.size();j++){
                    res += mapAB[-C[i]-D[j]];
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0454_H
