//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0104_H
#define LEETCODE_H0104_H

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

namespace h0104 {

    class Solution {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        int maxDepth(TreeNode *root) {
            if (root==NULL)
                return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
}

#endif //LEETCODE_H0104_H
