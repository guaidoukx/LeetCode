//
// Created by 项雅丽 on 2019/12/28.
//

#ifndef LEETCODE_H0437_H
#define LEETCODE_H0437_H

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

namespace h0437 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int ans = 0;

        int pathSum(TreeNode *root, int sum) {
            vector<int> path;
            dfs(root,path, sum);
            return ans;
        }

        void dfs(TreeNode *root, vector<int> &path, int sum) {
            if (root == NULL)
                return;
            path.push_back(root->val);
            int ss = 0;
            for (int i = path.size() - 1; i >=0; i--) {
                if (ss == sum) {
                    ans++;
                }
                ss += path[i];
            }
            if (root->left!=NULL) dfs(root->left, path, sum);
            if (root->right!=NULL) dfs(root->right, path, sum);
            path.pop_back();
        }
    };
}

#endif //LEETCODE_H0437_H
