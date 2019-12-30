//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0093_H
#define LEETCODE_H0093_H

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

namespace h0093 {
    class Solution {
    public:
        vector<string> res;

        vector<string> restoreIpAddresses(string s) {
            vector<int> ipSplit;
            getIPs(s, 0, ipSplit);
            return res;
        }

        void getIPs(const string &s, int index, vector<int> &ipSplit) {
            if (ipSplit.size() >= 4) { // 由于返回值是空，其实当ipSplit.size() >= 4的时候，不管怎么样都不需要继续了 直接return就好
                if (index == s.size() && vector2String(ipSplit).size() == s.size()+3)
                    res.push_back(vector2String(ipSplit));
                return;
            }
            for (int i = 1; i <= 3; i++) {
                if (index + i > s.size()) break; // 所以这里是可以包含 s.size()的
                int ip_ = stoi(s.substr(index, i)); // [index, index+i)
                if (ip_ >= 0 && ip_ <= 255) {
                    ipSplit.push_back(ip_);
                    getIPs(s, index + i, ipSplit);
                    ipSplit.pop_back();
                }
            }
            return;

        }

        string vector2String(vector<int> ipSplit) {
            string ip = to_string(ipSplit[0]);
            for (int i = 1; i < ipSplit.size(); i++) {
                ip = ip + "." + to_string(ipSplit[i]);
            }
            return ip;
        }

    };
}

#endif //LEETCODE_H0093_H
