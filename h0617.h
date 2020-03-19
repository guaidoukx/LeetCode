//
// Created by 项雅丽 on 2020/3/7.
//

#ifndef LEETCODE_H0617_H
#define LEETCODE_H0617_H

#include <iostream>

using namespace std;

namespace h0617 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    private:
        TreeNode *merge(TreeNode *t1, TreeNode *t2) {
            if (t1 == NULL && t2 == NULL) return NULL;
            if (t1 != NULL && t2 != NULL) {
                t1->val += t2->val;
                TreeNode *root = t1;
                root->left = merge(t1->left, t2->left);
                root->right = merge(t1->right, t2->right);
                return root;
            } else {
                return t1 != NULL ? t1 : t2;
            }
        }

    public:
        TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
            return merge(t1, t2);
        }
    };
}

#endif //LEETCODE_H0617_H
