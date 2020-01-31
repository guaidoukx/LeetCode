//
// Created by 项雅丽 on 2020/1/11.
//

#ifndef LEETCODE_DELE_H
#define LEETCODE_DELE_H

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
#include <unordered_map>

using namespace std;


class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0)
            return 0;
        int num = numbers[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (numbers[i] == num)
                cnt++;
            else {
                if (cnt == 0) {
                    num = numbers[i];
                    cnt++;
                } else
                    cnt--;
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (num == numbers[i])
                cnt++;
        }
        if (cnt * 2 > n)
            return num;
        else
            return 0;
    }
};


#endif //LEETCODE_DELE_H
