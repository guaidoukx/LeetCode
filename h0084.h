//
// Created by 项雅丽 on 2020/1/2.
//

#ifndef LEETCODE_H0084_H
#define LEETCODE_H0084_H

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

namespace h0084{
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            if (n == 0) return 0;
            if (n == 1) return heights[0];

            int start = 0;
            int end = n-1;
            vector<int> fromL(heights.size(), heights[0]), fromR(heights.size(), heights[n-1]);
            for ( int i=1;i<heights.size(); i++){
                if (heights[i] < fromL[i-1])
                    fromL[i] = heights[i];
                else
                    fromL[i] = fromL[i-1];
                if (heights[n-i-1] < fromR[n-i])
                    fromR[n-i-1] = heights[n-i-1];
                else
                    fromR[n-i-1] = fromR[n-i];
            }

            while (start <= end){
                fromR[start] fromL[end]
            }
        }
    };
}

#endif //LEETCODE_H0084_H
