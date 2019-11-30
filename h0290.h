//
// Created by 项雅丽 on 2019/11/29.
//

#ifndef LEETCODE_H0290_H
#define LEETCODE_H0290_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0290{
    class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            vector<string> strs = split_by_space(str);
            if (strs.size()!=pattern.size())
                return false;
            // 解法1
            /*if (pattern.size()!=strs.size())
                return false;

            map<char, int> dicC2String ;
            map<string, int> dicString2C;
            for (int i=0;i<pattern.size();i++){
                if (dicC2String.count(pattern[i]) == 0 && dicString2C.count(strs[i]) == 0) { // 没找到
                    dicC2String[pattern[i]] = i;
                    dicString2C[strs[i]] = i;
                } else if (dicC2String.count(pattern[i]) != 0 && dicString2C.count(strs[i]) != 0){ // 找到了
                    if (dicC2String[pattern[i]] != dicString2C[strs[i]])
                        return false;;
                } else
                    return false;
            }
            return true;*/

            // 解法2
            map<char, string> map1;
            map<string, char> map2;
            for (int i=0;i<strs.size();i++){
                map1[pattern[i]] = strs[i];
                map2[strs[i]] = pattern[i];
            }

            for (int i=0;i<strs.size();i++){
                if (map1[pattern[i]] != strs[i] ||map2[strs[i]] != pattern[i] )
                    return false;
            }
            return true;
        }

        vector<string> split_by_space(string str){
            vector<string> res;
            int l=0;
            for (int i=0; i<=str.size(); i++){
                if (str[i] == ' ' || i==str.size()){
                    res.push_back(str.substr(l,i-l));
                    cout<<l<<":"<<i<<"-"<<str.substr(l,i-l)<<" ";
                    l = i+1;
                }

            }
            return res;
        }
    };
}

#endif //LEETCODE_H0290_H
