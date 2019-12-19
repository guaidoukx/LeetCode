

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
#include <iomanip>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


struct cmp{
    bool operator ()(ListNode * a,ListNode * b){    //通过传入不同类型来定义不同类型优先级
        return a->val > b->val;    //最小值优先
    }
};

int main() {

priority_queue<ListNode *, vector<ListNode*>, cmp> q;
int arr[] = {1,4,5,1,3,4,2,6};

for (int i:arr){
    q.push(new ListNode(i));
}
while (!q.empty()){
    cout<<q.top()->val;
    q.pop();
}



















//    int n, p;
//    cin >> n >> p;
//    int arr[n];
//    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int,int>,pair<int,int>)>> q(myComp);
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//        q.push(make_pair(arr[i], i));
//    }
//    int time = 0;
//    int res[n];
//    for (int i = 0; i < n; i++)
//        res[i] = 0;
//
//    pair<int, int> poped;
//    while (!q.empty()) {
//        poped = q.top();
//        q.pop();
//        if (poped.first > time) {
//            time = poped.first + p;
//            res[poped.second] = time;
//        } else {
//            time = time + p;
//            res[poped.second] = time;
//        }
//    }
//    for (int i = 0; i < n - 1; i++)
//        cout << res[i] << " ";
//    cout << res[n - 1];
    return 0;

}