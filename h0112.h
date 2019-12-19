//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0112_H
#define LEETCODE_H0112_H

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

namespace h0112 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root==NULL)
                return false;
            if(root->val==sum && root->left==NULL && root->right==NULL)
                return true;
            return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
        }
    };
}

#endif //LEETCODE_H0112_H
