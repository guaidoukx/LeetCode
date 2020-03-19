//
// Created by 项雅丽 on 2020/2/5.
//

#ifndef LEETCODE_H1328_H
#define LEETCODE_H1328_H

#include <iostream>

using namespace std;

namespace h1328 {
    class Solution {
    public:
        string breakPalindrome(string palindrome) {
            int n = palindrome.size();
            if (n == 0 || n == 1) return "";

            string res = palindrome;
            for (int i = 0; i < n / 2; i++) {
                if (palindrome[i] == 'a' && i != n / 2 - 1)
                    continue;
                if (palindrome[i] != 'a') {
                    res[i] = 'a';
                    break;
                }
                if (i == n / 2 - 1) {
                    if (palindrome[i] == 'a') {
                        res[n - 1] = 'b';
                        break;
                    } else {
                        res[i] = 'a';
                        break;
                    }
                }
            }
            return res;

        }
    };
}

#endif //LEETCODE_H1328_H
