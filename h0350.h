//
// Created by 项雅丽 on 2019/11/26.
//

#ifndef LEETCODE_H0350_H
#define LEETCODE_H0350_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0350 {
    class Solution {
    public:
        vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
            map<int, int> map1, map2;
            for (int i:nums1)
                map1[i]++;
            for (int i:nums2)
                map2[i]++;

            vector<int> res;
            for (map<int,int>::iterator iter=map1.begin();iter!=map1.end();iter++){
                if (map2.find(iter->first)!=map2.end()){
                    int m = min(map1[iter->first], map2[iter->first]);
                    while (m>0){
                        res.push_back(iter->first);
                        m--;
                    }
                }
            }
            return res;
        }
    };
}

// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/wei-shi-yao-yong-map-by-vailing-2/
// 感觉这个解法很好，后续跟进。
#endif //LEETCODE_H0350_H
