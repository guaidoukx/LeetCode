//
// Created by 项雅丽 on 2019/12/30.
//

#ifndef LEETCODE_H0401_H
#define LEETCODE_H0401_H

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

namespace h0401 {

    class Solution {
    public:
        vector<string> res;
        vector<int> hours;
        vector<int> minutes;

        vector<string> readBinaryWatch(int num) {
            for (int i = 0; i <= 4; i++) {
                if (num - i <= 6) {
                    hours.clear();
                    minutes.clear();
                    getHour(i, 0, 0, 0);
                    getMinute(num - i, 0, 0, 0);
                    merge();
                }
            }
            return res;
        }

        // rows 1s, already has k 1s
        void getHour(int n, int k, int h, int start) {
            if (k == n) {
                if (h <= 11)
                    hours.push_back(h);
                return;
            }
            for (int i = start; i <= 4; i++)
                getHour(n, k + 1, h + pow(2, i), i + 1);

        }

        void getMinute(int n, int k, int m, int start) {
            if (k == n) {
                if (m <= 59)
                    minutes.push_back(m);
                return;
            }
            for (int i = start; i <= 6; i++)
                getMinute(n, k + 1, m + pow(2, i), i + 1);

        }

        void merge() {
            for (int h:hours) {
                for (int m:minutes) {
                    if (m <= 9)
                        res.push_back(to_string(h) + ":0" + to_string(m));
                    else
                        res.push_back(to_string(h) + ":" + to_string(m));
                }
            }
        }
    };
}

#endif //LEETCODE_H0401_H
