//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0113_H
#define LEETCODE_H0113_H

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

namespace h0113 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {// 深度优先遍历
    public:
        vector<vector<int>> pathSum(TreeNode *root, int sum) {
            vector<vector<int>> res;
            vector<int> out;
            dfs(root, sum, res, out);
            return res;
        }

        void dfs(TreeNode *node, int sum, vector<vector<int>> &res, vector<int> &out) {
            if (node == NULL)
                return;
            out.push_back(node->val);
            if (node->val == sum && node->left == NULL && node->right == NULL)
                res.push_back(out);
            if (node->left != NULL)
                dfs(node->left, sum - node->val, res, out);
            if (node->right != NULL)
                dfs(node->right, sum - node->val, res, out);
            out.pop_back();
        }
    };

    class Solution2 {
    public:
        vector<vector<int>> pathSum(TreeNode *root, int sum) {
            vector<vector<int>> res;
            vector<int> out;
            path(root, sum, res, out);
            return res;
        }

        void path(TreeNode *node, int sum, vector<vector<int>> &res, vector<int> &out) {
            if (node == NULL)
                return;
            out.push_back(node->val);
            if (node->val == sum && node->left == NULL && node->right == NULL) {
                res.push_back(out);
            }
            path(node->left, sum - node->val, res, out);
            path(node->right, sum - node->val, res, out);
            out.pop_back();
        }
    };
}


#endif //LEETCODE_H0113_H
