//
// Created by 项雅丽 on 2019/12/12.
//

#ifndef LEETCODE_H0199_H
#define LEETCODE_H0199_H

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

namespace h0199 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> rightSideView(TreeNode *root) {
            vector<int> res;
            if (root == NULL)
                return res;

            queue<TreeNode *> curs;
            TreeNode *tmp;
            curs.push(root);
            while (true) {
                queue<TreeNode *> nexts;
                bool toRecord = true;
                while (!curs.empty()) {
                    tmp = curs.front();
                    curs.pop();
                    if (toRecord) {
                        res.push_back(tmp->val);
                        toRecord = false;
                    }
                    if (tmp->right != NULL)
                        nexts.push(tmp->right);
                    if (tmp->left != NULL)
                        nexts.push(tmp->left);
                }
                if (nexts.empty())
                    break;
                curs = nexts;

            }
            return res;
        }
    };
}

#endif //LEETCODE_H0199_H
