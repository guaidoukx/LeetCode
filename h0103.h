//
// Created by 项雅丽 on 2019/12/12.
//

#ifndef LEETCODE_H0103_H
#define LEETCODE_H0103_H

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

namespace h0103 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            vector<vector<int>> res;
            if (root == NULL)
                return res;

            bool odd = true;
            stack<TreeNode *> curs;
            TreeNode *tmp;
            curs.push(root);

            while (true) {
                vector<int> level;
                stack<TreeNode *> nexts;
                while (!curs.empty()) {
                    tmp = curs.top();
                    curs.pop();
                    if (tmp != NULL) {
                        if (odd) {
                            nexts.push(tmp->left);
                            nexts.push(tmp->right);
                        } else {
                            nexts.push(tmp->right);
                            nexts.push(tmp->left);
                        }
                        level.push_back(tmp->val);
                    }
                }
                if (level.empty())
                    break;

                odd = !odd;
                res.push_back(level);
                curs = nexts;
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0103_H
