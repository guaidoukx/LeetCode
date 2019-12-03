//
// Created by 项雅丽 on 2019/12/2.
//

#ifndef LEETCODE_H0049_H
#define LEETCODE_H0049_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0049 {
    class Solution {
    public:
        // solution 1
        vector<vector<string>> groupAnagrams(vector<string> &strs) {
            vector<vector<string>>res;
            map<map<char, int>, vector<string>> mapOfMap;
            for(vector<string>::iterator iter=strs.begin(); iter!=strs.end();iter++){
                mapOfMap[getCharMap(*iter)].push_back(*iter);
            }
            for(map<map<char, int>, vector<string>>::iterator iter=mapOfMap.begin();iter!=mapOfMap.end(); iter++){
                res.push_back(iter->second);
            }
            return res;

        }

        static map<char, int> getCharMap(string s) {
            map<char, int> res;
            for (int i = 0; i < s.size(); i++) {
                res[s[i]]++;
            }
            return res;

        }

        // solution 2
        vector<vector<string>> groupAnagrams2(vector<string> &strs) {
            vector<vector<string>>res;
            map<string, vector<string>> mapOfMap;
            for(string str:strs){
                string tmp =str;
                sort(tmp.begin(), tmp.end());
                mapOfMap[tmp].push_back(str);
            }
            for(map<string, vector<string>>::iterator iter=mapOfMap.begin();iter!=mapOfMap.end(); iter++){
                res.push_back(iter->second);
            }
            return res;
        }

    };

}

#endif //LEETCODE_H0049_H
