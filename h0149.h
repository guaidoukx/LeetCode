//
// Created by 项雅丽 on 2019/12/3.
//

#ifndef LEETCODE_H0149_H
#define LEETCODE_H0149_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0149 {
    class Solution {
    public:
        int maxPoints(vector<vector<int>> &points) {
            // 特殊情况1 要是没有很多点？
            if (points.size() <= 2) {
                return points.size();
            }
            int res = 1;
            for (int i = 0; i < points.size() - 1; i++) {
                map<pair<int, int>, int> mapi;
                int same = 1; // 特殊情况2 要是有相同的坐标点，是与任何其他点都能在一条直线上的。单独考虑。
                int max_i = 0; // 每层都要考虑在这一层最大的点数是多少
                for (int j = i + 1; j < points.size(); j++) {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    if (dx == 0 && dy == 0) // 单独考虑相同坐标点的情况。
                        same++;
                    else {
                        pair<int, int> p = measure(dx, dy);
                        mapi[p]++;
                        max_i = max(max_i, mapi[p]);
                        cout << "i:" << i << "j:" << j << "   " << same << " " << p.first << " " << p.second << " "
                             << mapi[p] << endl;
                    }
                }
                max_i += same;
                res = max(res, max_i);
            }

            return res;
        }

        pair<int, int> measure(int x, int y) {
            if (x == 0)  // dx 为0 或者 dy 为0的时候，要单独考虑
                return make_pair(x, INT_MAX);

            if (y == 0)
                return make_pair(INT_MAX, y);

            // 辗转相除法找公约数只能是正数。
            int x1 = abs(x), y1 = abs(y);
            int z = y1;
            while (x1 % y1 != 0) {
                z = x1 % y1;
                x1 = y1;
                y1 = z;
            }
            // 特殊情况3 两个非常大的数相乘可能会溢出，要做类型转换
            // 特殊情况4 -1,-2 和 1，2表达的是同一个斜率。 -1,2 和 1,-2 表达的是同一个斜率。
            if ((long long) x * (long long) y > 0) {
                return make_pair(abs(x) / z, abs(y) / z);
            } else {
                return make_pair(-abs(x) / z, abs(y) / z);
            }
        }
    };
}

#endif //LEETCODE_H0149_H
