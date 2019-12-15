//
// Created by 项雅丽 on 2019/12/12.
//

#ifndef LEETCODE_H0107_H
#define LEETCODE_H0107_H

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

namespace h0107 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector<vector<int>> res;
            if (root == NULL)
                return res;

            stack<vector<int>> s;
            TreeNode *tmp;
            queue<TreeNode *> curQ;
            curQ.push(root);
            while (true) {
                queue<TreeNode *> nextQ;
                vector<int> level;
                while (!curQ.empty()) {
                    tmp = curQ.front();
                    curQ.pop();
                    if (tmp != NULL) {
                        nextQ.push(tmp->left);
                        nextQ.push(tmp->right);
                        level.push_back(tmp->val);
                    }
                }
                if (level.empty())
                    break;

                s.push(level);
                curQ = nextQ;
            }
            while (!s.empty()) {
                res.push_back(s.top());
                s.pop();
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0107_H
