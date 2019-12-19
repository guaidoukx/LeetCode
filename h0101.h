//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0101_H
#define LEETCODE_H0101_H

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

namespace h0101 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root==NULL)
                return true;
            return isSym(root->left, root->right);

        }
        bool isSym(TreeNode *rL, TreeNode *rR){
            if (rL==NULL && rR==NULL)
                return true;
            if (rL!=NULL && rR!=NULL)
                if (rL->val == rR->val)
                    return (isSym(rL->left, rR->right) && isSym(rL->right, rR->left));
            return false;
        }
    };
}

#endif //LEETCODE_H0101_H
