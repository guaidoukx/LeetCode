//
// Created by 项雅丽 on 2020/2/1.
//

#ifndef LEETCODE_H0238_H
#define LEETCODE_H0238_H

#include <iostream>
#include <vector>
using namespace std;

namespace h0238{
    class Solution1 {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res;
            int n = nums.size();
            if (n == 0)  return res;

            vector<int> front (n, 1);
             vector<int> back (n, 1);
            for (int i = 1; i < n; i++){
                front[i] = front[i-1] * nums[i-1];
                 back[n - 1 - i] = back[n-i] * nums[n-i];
            }
             for ( int i = 0; i < n; i++)
                 res.push_back(front[i] * back[i]);
            return res;
        }
    };

    class Solution2 {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> front;
            int n = nums.size();
            if (n == 0)  return front;

            front = vector<int>  (n, 1);
            for (int i = 1; i < n; i++)
                front[i] = front[i-1] * nums[i-1];

            int back = 1;
            for (int i = n-1; i >= 0; i--){
                front[i] = front[i] * back;
                back = back * nums[i];
            }
            return front;
        }
    };
}

#endif //LEETCODE_H0238_H
