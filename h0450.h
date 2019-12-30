//
// Created by 项雅丽 on 2019/12/28.
//

#ifndef LEETCODE_H0450_H
#define LEETCODE_H0450_H

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

namespace h0450 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        // 由于需要递归调用，返回的是删除key节点之后根节点
        TreeNode *deleteNode(TreeNode *root, int key) {
            if (root == NULL)
                return root;

            if (key < root->val) { // 还是写错了，return的是root
                root->left = deleteNode(root->left, key);
                return root;
            } else if (key > root->val) {
                root->right = deleteNode(root->right, key);
                return root;
            } else {
                if (root->left == NULL) {
                    TreeNode *rightNode = root->right;
                    delete root;
                    return rightNode;
                } else if (root->right == NULL) {
                    TreeNode *leftNode = root->left;
                    delete root;
                    return leftNode;
                } else {
                    TreeNode *rightMin = getRightMin(root->right);
                    rightMin->left = root->left;
                    delete root;
                    return rightMin;
                }
            }

        }

        // 找到右子树的最小值，并重新调整，当做根节点调整、返回，代替原来的要删除的节点
        // 也就是这个右子树的最小值，代替了要删除的节点的位置
        TreeNode *getRightMin(TreeNode *root) {
            if (root == NULL || (root->left == NULL && root->right == NULL)) return root;
            TreeNode *Min = root, *pre = NULL;
            while (Min->left != NULL) {
                pre = Min;
                Min = Min->left;
            }
            if (pre != NULL) {
                pre->left = Min->right;
                Min->right = root;
            }
            return Min;

        }
    };
}

#endif //LEETCODE_H0450_H
