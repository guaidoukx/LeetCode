//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0222_H
#define LEETCODE_H0222_H

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

namespace h0222 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int countNodes(TreeNode *root) {
            // solution 1
//            if (root==NULL)
//                return 0;
//            return countNodes(root->left)+countNodes(root->right) +1;
            // solution 2
            if(root==NULL)
                return 0;
            int left = countLevel(root->left);
            int right = countLevel(root->right);

            if (left==right){
                return pow(2, left) + countNodes(root->right);

            } else{
                return pow(2, right) + countNodes(root->left);
            }


        }
        int countLevel(TreeNode * root){
            int cnt = 0;
            while (root!=NULL){
                cnt++;
                root = root->left;
            }
            return cnt;
        }
    };
}

#endif //LEETCODE_H0222_H
