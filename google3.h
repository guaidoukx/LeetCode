//
// Created by 项雅丽 on 2019/12/8.
//

#ifndef LEETCODE_GOOGLE3_H
#define LEETCODE_GOOGLE3_H

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

namespace google3 {
    int a() {
        int n, V;
        cin >> n >> V;
        int vs[n], ws[n];
        int W = 0, VV = 0;
        for (int i = 0; i < n; i++) {
            cin >> vs[i] >> ws[i];
            W += ws[i];
            VV += vs[i];
        }
        int dp[n + 1][W + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= W; i++) {
            dp[0][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= W; j++) {
                if (j < ws[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - ws[i]] + vs[i]);
                }
            }
        }

        for (int i = 0; i <= W; i++) {
            if (dp[n][i] >= V) {
                cout << i;
                break;
            }
        }
        return 0;
    }
}

#endif //LEETCODE_GOOGLE3_H
