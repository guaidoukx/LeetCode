//
// Created by 项雅丽 on 2019/11/30.
//

#ifndef LEETCODE_H0083_H
#define LEETCODE_H0083_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0083 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *dummyHead = new ListNode(0);
            ListNode *p = head;
            while (p != NULL) {
                while (p->next != NULL && p->val == p->next->val) {
                    p->next = p->next->next;
                } p = p->next;
            }
            return head;
        }
    };
}

#endif //LEETCODE_H0083_H
