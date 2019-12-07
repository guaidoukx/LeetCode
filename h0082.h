//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0082_H
#define LEETCODE_H0082_H

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

namespace h0082 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode *dummyHead = new ListNode(-1);
            dummyHead->next = head;
            ListNode *cur = head, *pre = dummyHead;
            bool isDup = false;
            while (cur != NULL) {
                if (cur->next != NULL && cur->val == cur->next->val) {
                    cur = cur->next;
                    isDup = true;
                    continue;
                }
                if (isDup==true){
                    // 只要有重复过的，那么当前cur指向重复的最后一个元素，pre需要指向当前cur的后一个元素，但是pre其实不动
                    cur = cur->next;
                    pre->next = cur;
                    isDup=false;
                    continue; // 这时候需要继续判断当前的cur是不是有重复元素。
                }
                cur = cur->next;
                pre = pre->next;

            }
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0082_H
