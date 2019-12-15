//
// Created by 项雅丽 on 2019/12/8.
//

#ifndef LEETCODE_H0071_H
#define LEETCODE_H0071_H

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

namespace h0071 {

#include<stack>
#include<string>

#include<stack>
#include<string>

    class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> s;
            string tmp = "";
            int i = 1;
            while (true) {
                if (i >= path.size())
                    break;
                while (path[i] != '/') {
                    tmp += path[i];
                    if (i < path.size() - 1) i++;
                    else break;
                }
                if (tmp != "." && tmp != ".." && tmp != "") {
                    s.push(tmp);
                    tmp = "";
                } else {
                    if (tmp == "..")
                        if (!s.empty())
                            s.pop();

                    tmp = "";
                }
                i++;
            }

            string res = "";
            while (!s.empty()) {
                res = "/" + s.top() + res;
                s.pop();
            }
            if (res.size() ==0)
                res = "/";
            return res;


        }
    };
}

#endif //LEETCODE_H0071_H
