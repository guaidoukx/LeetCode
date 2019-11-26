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

using namespace std;
// 这不太行，我不会，我还要看看。
namespace h0076{
    class Solution {
    public:
        string minWindow(string s, string t) {
            string res = "";
            cout <<"s.size: "<<s.size()<<" t.size:"<<t.size()<<endl;
            map<char,int> mapT,mapS;
            for (char c:t)
                mapT[c]++;

            if (s.size() < mapT.size() || mapT.size() == 0)
                return res;

            int recordl,recordr;
            int l=0, r=0,min_=s.size();
            while(l + mapT.size() <= s.size() && r < s.size()){
                cout << "l:" << l << " r:" << r << " setS.size:" << mapS.size() << "  ";
                for (map<char,int>::iterator iter=mapS.begin(); iter != mapS.end(); iter++)
                    cout<< iter->first<<":"<<iter->second <<" ";
                cout<<endl;
                if (mapS.size() < mapT.size()){ // 没找全
                    if (mapT.find(s[r]) != mapT.end()){ // 找到了
                        mapS[s[r]]++;
                    }
                    r++;
                } else{
                    if (r-l < min_){
                        min_ = r-l;
                        recordl = l;
                        recordr = r;
                        cout<<"here";
                    }

                    if (mapS[s[l]] > 1 )
                        mapS[s[l]]--;
                    else
                        mapS.erase(s[l]);
                    l++;
                }
            }
            if (recordl==NULL)
                return res;

            res = s.substr(recordl,recordr);
            cout<<recordl<<' '<<recordr<<endl;

            return res;
        }
    };

}

#endif //LEETCODE_H0076_H
