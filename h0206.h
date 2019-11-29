//
// Created by 项雅丽 on 2019/11/28.
//

#ifndef LEETCODE_H0206_H
#define LEETCODE_H0206_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0206 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *reverseList(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode *pre = NULL;
            ListNode *cur = head;
            ListNode *nex;
            while (cur) {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            return pre;
        }
    };
}

#endif //LEETCODE_H0206_H
