

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


//    map<map<char, int>, int> a;
//    map<char, int> a1{{'a',2},{'c',3}};
//    map<char, int> a2{{'a',2},{'c',3}};
//    a.insert({a1,2});
//    a.insert({a1,3});
//    cout<<(a.size());

//    vector<vector<int>> a{{1, 2},{3, 4}};
//    h0149::Solution solution = h0149::Solution();
//    solution.measure((118), (-788));


#include <iostream>
//#include <iomanip>
#include <map>
#include <unordered_map>
//#include <vector>
#include <set>
//#include <string>
//#include <cmath>
//#include <array>
#include <queue>
//#include <stack>
//#include <functional>
//#include <numeric>
#include <unordered_set>
//#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void get(vector<int> &nums){
    vector<int> x = nums;
    nums[1] = 100;
    for (int i = 0; i< nums.size(); i++){
        cout<<x[i]<<endl;
    }
}


int main() {
    set<int> s;
    unordered_map<char, int> cnt;
    cnt['d'] = 0;
    for(unordered_map<char, int>::iterator iter=cnt.begin(); iter!=cnt.end();iter++ ){
        cout<<iter->first<<endl;
    }
}
















