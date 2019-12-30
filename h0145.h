//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0145_H
#define LEETCODE_H0145_H

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

namespace h0145 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            stack<TreeNode *> s;
            vector<int> res;
            TreeNode *cur = root, *pre = NULL;
            //  cur 代表第一次访问一个节点的时候
            while (cur != NULL || !s.empty()) {
                if (cur != NULL) {
                    s.push(cur);
                    cur = cur->left;
                }else{
                    // tmp是第二次或第三次访问节点，
                    TreeNode *tmp = s.top();
                    // pre来代表这个节点已经经过第三次访问，不需要继续访问了，
                    // 那么这个点的父亲节点也正在经历第三次访问，按照第三次访问的操作就可以了。
                    if (tmp->right==NULL || tmp->right==pre){
                        res.push_back(tmp->val);
                        pre = tmp;
                        s.pop();
                    } else{
                        cur = tmp->right;
                    }
                }
            }

            return res;
        }

    };
}

#endif //LEETCODE_H0145_H
