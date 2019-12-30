//
// Created by 项雅丽 on 2019/12/27.
//

#ifndef LEETCODE_H0129_H
#define LEETCODE_H0129_H

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

namespace h0129 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int sumNumbers(TreeNode *root) {

            vector<int> out;
            int res = 0;
            dfs(root, out, res);
            return res;
        }

        void dfs(TreeNode *root, vector<int> &out, int &res) {
            if (root == NULL)
                return;
            out.push_back(root->val);
            if (root->left == NULL && root->right == NULL) {
                res += vectorSum(out);
            }
            if (root->left != NULL)
                dfs(root->left, out, res);
            if (root->right != NULL)
                dfs(root->right, out, res);
            out.pop_back();
        }

        int vectorSum(vector<int> vec) {
            int res = 0;
            for (int i = 0; i < vec.size(); i++) {
                res = res * 10 + vec[i];
            }
            return res;
        }
    };

    class Solution1 {
    public:
        int ans = 0;

        int sumNumbers(TreeNode *root) {
            dfs(root, 0);
            return ans;
        }

        void dfs(TreeNode *root, int cur) {
            if (root == NULL)
                return;
            cur = cur * 10 + root->val;
            if (root->left == NULL && root->right == NULL) {
                ans += cur;
            }
            if (root->left != NULL) dfs(root->left, cur);
            if (root->right != NULL) dfs(root->right, cur);
            cur = cur / 10;
        }
    };
}

#endif //LEETCODE_H0129_H
