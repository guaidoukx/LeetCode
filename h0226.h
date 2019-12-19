//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0226_H
#define LEETCODE_H0226_H

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

namespace h0226 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode *invertTree(TreeNode *root) {
            if (root==NULL)
                return NULL;
            TreeNode* tmp = invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = tmp;
            return root;
        }
    };
}

#endif //LEETCODE_H0226_H
