//
// Created by 项雅丽 on 2019/11/21.
//

#ifndef LEETCODE_H0345_H
#define LEETCODE_H0345_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

namespace h0345{
    class Solution {
    public:
        string reverseVowels(string s) {
            if (s.size()==0)
                return s;

            int i=0,j=s.size()-1;
            while (i<j){
                char si = tolower(s[i]);
                char sj = tolower(s[j]);
                if ((si=='i'||si=='o'||si=='a'||si=='e'||si=='u')&&(sj=='i'||sj=='o'||sj=='a'||sj=='e'||sj=='u')){
                    swap(s[i], s[j]);
                    i++;
                    j--;
                } else if (!(si=='i'||si=='o'||si=='a'||si=='e'||si=='u')){
                    i++;
                } else
                    j--;
            }
            return s;
        }
    };
}

#endif //LEETCODE_H0345_H
