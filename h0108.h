//
// Created by 项雅丽 on 2019/12/29.
//

#ifndef LEETCODE_H0108_H
#define LEETCODE_H0108_H

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

namespace h0108 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums) {
            if (nums.size()==0)
                return NULL;
            return getBST(nums, 0, nums.size()-1);
        }
        TreeNode *getBST(vector<int> &nums, int l ,int r){
            if (r-l>=2){
                int mid = l + (r-l)/2;
                TreeNode *root = new TreeNode(nums[mid]);
                root->left = getBST(nums, l, mid-1);
                root->right = getBST(nums, mid+1, r);
                return root;
            }
            if (r-l==0)
                return new TreeNode(nums[l]);
            else{
                TreeNode *root = new TreeNode(nums[r]);
                root->left = new TreeNode(nums[l]);
                return root;
            }
        }
    };
}

#endif //LEETCODE_H0108_H
