//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0230_H
#define LEETCODE_H0230_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0230 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int kthSmallest(TreeNode *root, int k) {
            stack<TreeNode*> s;
            int cnt=0;
            TreeNode *cur = root;
            while (cur!=NULL || !s.empty()){
                if (cur!=NULL){
                    s.push(cur);
                    cur = cur->left;
                } else{
                    TreeNode *tmp = s.top();
                    s.pop();
                    cnt ++;
                    if (cnt == k) return tmp->val;
                    cur = tmp->right;
                }
            }
            return -1;
        }
    };
}

#endif //LEETCODE_H0230_H
