//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0110_H
#define LEETCODE_H0110_H

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

namespace h0110 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    private:
        bool res = true;
    public:
        bool isBalanced(TreeNode *root) {
            if (root == NULL)
                return true;
            helper(root);
            return res;

        }

        int helper(TreeNode *root) {
            if (root == NULL)
                return 0;
            while (res) {
                int left = helper(root->left);
                int right = helper(root->right);
                if (abs(left - right) > 1)
                    res = false;
                return max(helper(root->left), helper(root->right)) + 1;
            }
            return 0;
        }
    };
}
// 比较好的写法 https://leetcode-cn.com/problems/balanced-binary-tree/solution/ti-qian-zu-duan-fa-gei-da-lao-de-xie-fa-xie-zhu-sh/
#endif //LEETCODE_H0110_H
