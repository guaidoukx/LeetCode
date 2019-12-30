//
// Created by 项雅丽 on 2019/12/28.
//

#ifndef LEETCODE_H0098_H
#define LEETCODE_H0098_H

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

namespace h0098 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {

    public:
        bool isValidBST(TreeNode *root) {
            // 这里的边界条件很重要啊
            return isBST(root, LONG_MAX, LONG_MIN);
        }

        bool isBST(TreeNode *root, long max_, long min_) {
            if (root == NULL)
                return true;
            if (root->val >= max_ || root->val <= min_)
                return false;
            return isBST(root->left, root->val, min_) && isBST(root->right, max_, root->val);
        }
    };
}

#endif //LEETCODE_H0098_H
