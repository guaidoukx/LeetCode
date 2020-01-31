//
// Created by 项雅丽 on 2020/1/1.
//

#ifndef LEETCODE_H0337_H
#define LEETCODE_H0337_H

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

namespace h0337 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;

        TreeNode(int x) {
            val = x;
            left = NULL;
            right = NULL;
        }
    };

    class Solution {
    public:
        int rob(TreeNode *root) {
            vector<int> r = getRob(root);
            return max(r[0], r[1]);

        }

        vector<int> getRob(TreeNode *root) {
            vector<int> res(2, 0);
            if (root == NULL)
                return res;
            vector<int> left = getRob(root->left);
            vector<int> right = getRob(root->right);

            res[0] = max(left[0], left[1]) + max(right[0], right[1]);
            res[1] = left[0] + right[0] + root->val;
            return res;
        }
    };
}


#endif //LEETCODE_H0337_H
