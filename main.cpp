#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <array>
#include <queue>
#include "h0283.h"
#include "h0027.h"
#include "h0080.h"
#include "h0088.h"
#include "h0215.h"
#include "h0209.h"
#include "h0076.h"


using namespace std;

int main() {

//    set<int> s;
//    cout<<(s.find(2)!=s.end());
//    string str = "dog cat cat dog";
//    pair<int, int> res;
//    map<int, int> res1;
//    array<int,3> arr1({1,2,3});
//    array<int,3> arr2({2,1,3});
//    s.insert(arr1);
//    s.insert(arr2);
//    cout<<(arr1==arr2)<<endl;
//    cout<<"arr1:"<<&arr1<<" arr2:"<<&arr2<<endl;
//    int arr3[] = {1,3,5};
//    int arr4[] = {1,3,5};
//    cout<<(arr3==arr4)<<endl;
//    cout<<"arr3:"<<&arr3<<" arr4:"<<&arr4<<endl;

//    set<array<int,3>> s;
//    for(set<array<int,3>>::iterator iter=s.begin();iter!=s.end();iter++) {
//        for(array<int,3>::const_iterator it=iter->begin();it!=iter->end();it++){
//            cout << *it << " ";
//        cout<<endl;
//    }
//    set<priority_queue<int>> s;
//    priority_queue<int> a = {1, 2};
//    priority_queue<int> b = {1, 2};
//    s.insert(a);
//    s.insert(b);
//    cout << s.size();

//    map<int, set<pair<int, int>>> a;
//    set<pair<int, int>> b;
//    b = a[2];
    set<vector<int>> a;
    vector<int> b = {1,2};
    vector<int> c = {1,2,4};
    a.insert(b);
    b.push_back(3);
    a.insert(b);
    a.insert(c);
    for (set<vector<int>>::iterator iter= a.begin();iter!=a.end(); iter++){
        cout<<&iter<<" ";
        for (vector<int>::const_iterator it=iter->begin();it!=iter->end();it++){
            cout<<&it<<" " ;
            cout<<*it<<" ";
        }cout<<endl;
    }

    cout<<

}