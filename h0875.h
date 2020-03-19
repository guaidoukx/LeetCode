//
// Created by 项雅丽 on 2020/2/5.
//

#ifndef LEETCODE_H0875_H
#define LEETCODE_H0875_H

#include <iostream>
#include <vector>

using namespace std;

namespace h0875 {
    class Solution {
    private:
        bool canFinish(vector<int> &piles, int H, int K) {
            int n = piles.size();
            if (n == 0) return true;
            if (K == 0) return false;
            long long times = 0;
            for (int i = 0; i < n; i++) {
                if (piles[i] % K == 0)
                    times = times + piles[i] / K;
                else
                    times = times + piles[i] / K + 1;
                // cout << "times:" << times <<endl;
            }
            // cout << "H:" <<H << " K:"<<K<<" "<<times;
            if (times <= H) return true;
            else return false;
        }

    public:
        int minEatingSpeed(vector<int> &piles, int H) {
            int n = piles.size();
            if (n == 0) return 0;
            long long s = 0;
            for (int i = 0; i < n; i++)
                s += piles[i];
            if (s == 0) return true;
            // cout << s << endl;
            cout << canFinish(piles, H, 30) << " " << canFinish(piles, H, 29) << endl;

            long long l = 1, r = s;
            while (l <= r) {
                long long mid = l + (r - l) / 2;
                if (canFinish(piles, H, mid) && !canFinish(piles, H, mid - 1))
                    return mid;
                if (canFinish(piles, H, mid))
                    r = mid - 1;
                else
                    l = mid + 1;
                // cout << mid << " ";
            }
            return -1;
        }
    };
}

#endif //LEETCODE_H0875_H
