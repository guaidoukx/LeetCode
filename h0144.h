//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0144_H
#define LEETCODE_H0144_H

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

namespace h0144 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            stack<TreeNode *> s;
            vector<int> res;
            TreeNode *tmp = root;
            // 先一直向左压入栈
            // 压入栈的时候把值加进res
            while (tmp != NULL || !s.empty()) {
                if (tmp != NULL) {
                    res.push_back(tmp->val);
                    s.push(tmp);
                    tmp = tmp->left;
                } else {// tmp为NULL时，开始从栈中pop，
                    tmp = s.top();
                    s.pop();
                    // 同时开始把当前这个节点的右节点压入栈中
                    tmp = tmp->right;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0144_H
