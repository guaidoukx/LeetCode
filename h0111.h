//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0111_H
#define LEETCODE_H0111_H

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

namespace h0111 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int minDepth(TreeNode *root) {
            // 也就是分几种情况 就是叶子节点的情况
            if(root!=NULL && root->left==NULL &&root->right==NULL)
                return 1;
            // 叶子，左孩子，右孩子都不为空的情况
            else if(root!=NULL && root->left!=NULL &&root->right!=NULL)
                return  min(minDepth(root->left), minDepth(root->right))+1;
            // 有一个孩子为空的情况，这时候，这颗树的深度是大的那边的深度
            else if(root!=NULL)
                return max(minDepth(root->left), minDepth(root->right))+1;
            // 其实一般不会走到这儿，这是为了防止root就是为空的情况
            else
                return 0;
        }
    };
}

#endif //LEETCODE_H0111_H
