//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0100_H
#define LEETCODE_H0100_H

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

namespace h0100 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p==NULL && q==NULL)
                return true;
            if (p!=NULL && q!=NULL)
                if (p->val == q->val)
                    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            return false;


        }
    };
}

#endif //LEETCODE_H0100_H
