//
// Created by 项雅丽 on 2019/12/27.
//

#ifndef LEETCODE_H0404_H
#define LEETCODE_H0404_H

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

namespace h0404 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode *root) {
            // 解法1 递归
            if (root == NULL || (root->left == NULL && root->right == NULL))
                return 0;
            if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
                return root->left->val + sumOfLeftLeaves(root->right);
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

            // 解法1.1 递归，但是用了引用，直接修改int，但是有点小题大做啦。
            int res = 0;
            helper(root, res);
            return res;
        }
        // 解法1.1的函数
        void helper(TreeNode *root, int &res) {
            if (root == NULL || (root->left == NULL && root->right == NULL))
                res += 0;

            else if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
                res += (root->left->val + sumOfLeftLeaves(root->right));

            res += (sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right));
        }
    };
}

#endif //LEETCODE_H0404_H
