//
// Created by 项雅丽 on 2019/12/27.
//

#ifndef LEETCODE_H0257_H
#define LEETCODE_H0257_H

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

namespace h0257 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<string> res;

        vector<string> binaryTreePaths(TreeNode *root) {
            if (root != NULL) {
                // 考虑第一个值在里面
                string s = to_string(root->val);
                if (root->left == NULL && root->right == NULL)
                    // 万一只有root一个值，但是又没有经历判断是否是叶子节点的情况，所以要判断一下
                    res.push_back(s);
                else {
                    dfs(root->left, s);
                    dfs(root->right, s);
                }
            }
            return res;
        }

        void dfs(TreeNode *root, string s) {
            if (root == NULL)
                return;
            string pre = s;
            s = s + "->" + to_string(root->val); // 这时候就得保证第一个值已经在里面的情况
            if (!root->left && !root->right) {
                res.push_back(s);
            }
            if (root->left != NULL) dfs(root->left, s);
            if (root->right != NULL) dfs(root->right, s);
            s = pre;
        }

    };
}

#endif //LEETCODE_H0257_H
