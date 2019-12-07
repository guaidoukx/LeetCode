//
// Created by 项雅丽 on 2019/12/5.
//

#ifndef LEETCODE_PDD3_H
#define LEETCODE_PDD3_H

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

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int M, A, R;
    cin >> M >> A >> R;
    int row = min(A - 1, R - 1);
    int col = R;

    float xishu = (float) (M - A + 1) / R;
    cout << setiosflags(ios::fixed) << setprecision(5) << xishu;
    int a[row][col];
    for (int j = 1; j < col; j++)
        a[0][j] = 0;
    for (int i = 0; i < row; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    cout << endl;
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; ++j) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    float res = 1.0;
    for (int j = 0; j < col; j++) {
        float rowSum = 0.0;
        for (int i = 0; i < row; i++) {
            rowSum += a[i][j];
        }
        res += rowSum / pow(R, j + 1);
        cout << rowSum / pow(R, j + 1) << " " << res << endl;
    }

    res = res * xishu;
    if (res < 1.0)
        cout << setiosflags(ios::fixed) << setprecision(5) << res;
    else
        cout << setiosflags(ios::fixed) << setprecision(5) << 1.00000;

    return 0;
}

#endif //LEETCODE_PDD3_H
