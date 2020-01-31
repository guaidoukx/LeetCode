//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0070_H
#define LEETCODE_H0070_H

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

namespace h0070{
    class Solution {
    public:
        int climbStairs(int n) {
            vector<int> arr(n+1, -1);
            arr[0] = 1;
            arr[1] = 1;
            for (int i=2;i<=n;i++){
                arr[i] = arr[i-1] + arr[i-2];
            }
            return arr[n];
        }
    };
}

#endif //LEETCODE_H0070_H
