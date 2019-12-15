//
// Created by 项雅丽 on 2019/12/12.
//

#ifndef LEETCODE_H0102_H
#define LEETCODE_H0102_H

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

namespace h0102 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> res;
            if (root == NULL)
                return res;

            queue<TreeNode *> curs;
            TreeNode *tmp;
            curs.push(root);

            while (true) {
                vector<int> level;
                queue<TreeNode *> nexts;
                while (!curs.empty()) {
                    tmp = curs.front();
                    curs.pop();
                    if (tmp != NULL) {
                        nexts.push(tmp->left);
                        nexts.push(tmp->right);
                        level.push_back(tmp->val);
                    }
                }
                if (level.empty())
                    break;

                res.push_back(level);
                curs = nexts;
            }
            return res;
        }
    };
}

#endif //LEETCODE_H0102_H
