#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include "h0283.h"
#include "h0027.h"
#include "h0080.h"
#include "h0088.h"
#include "h0215.h"
#include "h0209.h"
#include "h0076.h"


using namespace std;

int main() {

    h0076::Solution solution = h0076::Solution();

//    cout<<solution.minWindow("ADOBECODEBANC","ABC");

    string t = "ABDFSDAD";
    map<char,int> mapT,mapS;
    for (char c:t)
        mapT[c]++;

    for (map<char,int> ::iterator iter = mapT.begin(); iter!=mapT.end();iter++){
        cout<<iter->first<<":"<<iter->second<<" ";
    }
    if (mapT['A']==mapS['A']){}


    cout<<mapS.size()<<endl;

}