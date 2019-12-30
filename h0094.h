//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0094_H
#define LEETCODE_H0094_H

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

namespace h0094 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            stack<TreeNode *> s;
            vector<int> res;
            TreeNode *tmp = root;
            // 先一直向左压入栈
            while (tmp != NULL || !s.empty()) {
                if (tmp != NULL) {
                    s.push(tmp);
                    tmp = tmp->left;
                } else {// tmp为NULL时，开始从栈中pop，
                    tmp = s.top();
                    s.pop();
                    // pop的时候把值加进res
                    res.push_back(tmp->val);
                    // 同时开始把当前这个节点的右节点压入栈中
                    tmp = tmp->right;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0094_H
