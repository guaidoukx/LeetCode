

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
#include <unordered_set>

using namespace std;

class Solution1_{
    vector<int> begin;
    vector<int> end;

    vector<int> addrSearching(int pointer){
        int n = begin.size();
        int index = binarySearch(begin, pointer, 0, n-1);
        vector<int> res;
        res.push_back(begin[index]);
        res.push_back(end[index]);
        return  res;
    }
    int binarySearch(vector<int> &nums, int target ,int l, int r){
        if (l > r) return -1;
        int mid = l + (r-l) /2;
        if (nums[mid] <= target && nums[mid+1]>target) return mid;
        if (nums[mid] > target) return binarySearch(nums, target, l, mid -1);
        if (nums[mid+1]<target ) return binarySearch(nums, target, mid +1, r);
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2_ {
public:
    TreeNode *sort(TreeNode *root) {
        stack<TreeNode *>s;
        TreeNode* tmp = root;
        TreeNode * head;
        while (tmp != NULL || !s.empty()) {
            if (tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            }

            else {
                tmp = s.top();
                s.pop();

                tmp->right = s.top();
            }
        }

    }
};





int main() {
    set<int> a;
    a.er


}

















