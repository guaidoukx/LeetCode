//
// Created by 项雅丽 on 2020/2/1.
//

#ifndef LEETCODE_H0655_H
#define LEETCODE_H0655_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace h0655 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    private:
        int m, n;
        vector<vector<string>> res;

        int getDepth(TreeNode *root) {
            if (root == NULL) return 0;
            return max(getDepth(root->left), getDepth(root->right)) + 1;
        }

        void fill(int r, int c, TreeNode *root) {
            res[r][c] = to_string(root->val);
            if (m - 2 - r < 0) return;

            int gap = pow(2, m - 2 - r);
            if (root->left != NULL)
                fill(r + 1, c - gap, root->left);
            if (root->right != NULL)
                fill(r + 1, c + gap, root->right);
            return;
        }

    public:
        vector<vector<string>> printTree(TreeNode *root) {
            if (root == NULL) return {{""}};

            m = getDepth(root);
            n = pow(2, m) - 1;
            res = vector<vector<string>>(m, vector<string>(n, ""));

            fill(0, pow(2, m - 1) - 1, root);
            return res;
        }
    };
}

#endif //LEETCODE_H0655_H
