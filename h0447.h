//
// Created by 项雅丽 on 2019/12/2.
//

#ifndef LEETCODE_H0447_H
#define LEETCODE_H0447_H

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <cmath>

using namespace std;

namespace h0447 {
    class Solution {
    public:
        int numberOfBoomerangs(vector<vector<int>> &points) {
            int res=0;
            for(int i=0;i<points.size();i++){
                unordered_map<int, int> m;
                for (int j=0;j<points.size();j++){
                    if (j!=i){
                        m[squareDistance(points[i], points[j])] ++;
                    }
                }
                for (unordered_map<int, int>::iterator iter=m.begin();iter!=m.end();iter++){
                    res += (iter->second) * (iter->second -1);
                }
            }
            return res;
        }

        int squareDistance(vector<int> &a, vector<int> &b) {
            return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
        }
    };
}

#endif //LEETCODE_H0447_H
