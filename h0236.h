//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0236_H
#define LEETCODE_H0236_H

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

namespace h0236 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (root==NULL || root==p || root==q)
                return root;
            TreeNode* l = lowestCommonAncestor(root->left, p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);
            if (l!=NULL && r!=NULL) return root;
            return  l != NULL ? l : r;
        }
    };
}

#endif //LEETCODE_H0236_H
