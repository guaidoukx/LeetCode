//
// Created by 项雅丽 on 2019/11/25.
//

#ifndef LEETCODE_H0003_H
#define LEETCODE_H0003_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>

using namespace std;

namespace h0003 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length() == 0)
                return 0;
            int arr[256];
            memset(arr, -1, sizeof(arr));
            int l = 0, r, res = 0;

            // [l,r]
            for (r = 0; r < s.length(); r++) {
                if (arr[s[r]] == -1 || arr[s[r]] < l) {
                    res = max(res, r - l + 1);
                } else {
                    l = arr[s[r]] + 1;
                    res = max(res, r - l + 1);
                }
                arr[s[r]] = r;
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0003_H
