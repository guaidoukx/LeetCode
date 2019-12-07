//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0150_H
#define LEETCODE_H0150_H

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

namespace h0150 {
    class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> s;
            int a, b, res;
            bool isVisted=false;
            for (string token :tokens) {
                if (token != "+" && token != "-" && token != "*" && token != "/") {
                    int d = atoi(token.c_str());
                    s.push(d);
                    if (!isVisted){ // 要记录第一个为数字的token，当做res。万一只有这一个数呢。
                        res = d;
                        isVisted = true;
                    }
                } else {
                    b = s.top();
                    s.pop();
                    a = s.top();
                    s.pop();
                    if (token == "+") {
                        res = a + b;
                        s.push(res);
                    } else if (token == "-") {
                        res = a - b;
                        s.push(res);
                    } else if (token == "*") {
                        res = a * b;
                        s.push(res);
                    } else {
                        res = a / b;
                        s.push(res);
                    }
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0150_H
