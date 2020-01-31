//
// Created by 项雅丽 on 2019/11/26.
//

#ifndef LEETCODE_H0076_H
#define LEETCODE_H0076_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <unordered_set>

using namespace std;
// 这不太行，我不会，我还要看看。
namespace h0076 {
    class Solution {
    public:
        string minWindow(string s, string t) {
            string res = "";
            cout << "s.size: " << s.size() << " t.size:" << t.size() << endl;
            map<char, int> mapT, mapS;
            for (char c:t)
                mapT[c]++;

            if (s.size() < mapT.size() || mapT.size() == 0)
                return res;

            int recordl, recordr;
            int l = 0, r = 0, min_ = s.size();
            while (l + mapT.size() <= s.size() && r < s.size()) {
                cout << "l:" << l << " r:" << r << " setS.size:" << mapS.size() << "  ";
                for (map<char, int>::iterator iter = mapS.begin(); iter != mapS.end(); iter++)
                    cout << iter->first << ":" << iter->second << " ";
                cout << endl;
                if (mapS.size() < mapT.size()) { // 没找全
                    if (mapT.find(s[r]) != mapT.end()) { // 找到了
                        mapS[s[r]]++;
                    }
                    r++;
                } else {
                    if (r - l < min_) {
                        min_ = r - l;
                        recordl = l;
                        recordr = r;
                        cout << "here";
                    }

                    if (mapS[s[l]] > 1)
                        mapS[s[l]]--;
                    else
                        mapS.erase(s[l]);
                    l++;
                }
            }
            if (recordl == NULL)
                return res;

            res = s.substr(recordl, recordr);
            cout << recordl << ' ' << recordr << endl;

            return res;
        }
    };

    class Solution1 {
    public:
        string minWindow(string s, string t) {
            string res = "";
            int sLength = s.size();
            int tLength = t.size();
            if (sLength == 0 || sLength < tLength) return res;

            map<char, int> origin, now;
            unordered_set<char> symbols; // 记录不符合要求的字母集合
            for (int i = 0; i < tLength; i++) {
                origin[t[i]]++;
                symbols.insert(t[i]);
            }
            int i = 0, j = 0;
            int rl = 0, min_ = sLength;
            while (i < sLength && j < sLength) {
                while (symbols.size() != 0 && j < sLength) {
                    if (origin.find(s[j]) != origin.end()) { // 所有这一切都基于这在字符集合中
                        now[s[j]]++;
                        if (now[s[j]] >= origin[s[j]] && symbols.find(s[j]) != symbols.end())
                            symbols.erase(s[j]);
                    }
                    j++; // cout<<"jiajin"<<i<<' '<<j<<endl; //最终j指向的是满足字符条件的后一个字符 CABCR找ABC 指向的是R
                }

                while (symbols.empty() && i < sLength) {
                    if (origin.find(s[i]) != origin.end()) {
                        now[s[i]]--;
                        if (symbols.find(s[j]) == symbols.end() && now[s[i]] < origin[s[i]])
                            symbols.insert(s[i]);
                    }
                    i++; // 最终j指向的是满足字符条件的后一个字符  CABCR找ABC 指向的B
                }
                if (j - i + 1 <= min_) { // 因为是前闭后闭，所以长度要+1
                    min_ = j - i + 1;
                    rl = i;
                }
            }
            if (rl == 0) return "";
            return s.substr(rl - 1, min_);

        }
    };

}

#endif //LEETCODE_H0076_H
