//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0024_H
#define LEETCODE_H0024_H

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

namespace h0024 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode *dummyHead = new ListNode(-1);
            dummyHead->next = head;

            ListNode *p = head, *q = dummyHead;
            while (p != NULL && p->next != NULL) {
                q->next = p->next;
                p->next = p->next->next;
                q->next->next = p;

                q = p;
                p = p->next;
            }
            q->next = p;
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0024_H
