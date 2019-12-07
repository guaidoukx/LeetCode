//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0147_H
#define LEETCODE_H0147_H

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

namespace h0147 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *insertionSortList(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode *dummyHead = new ListNode(-1);
            dummyHead->next = head;
            ListNode *p = dummyHead, *q = head->next;
            head->next = NULL; // 有一个重要的问题，其实p、q两个指针之间是要断的，不然从p到q的节点会构成自环
            ListNode *qRecord;

            // dummyHead -> p(head) -> *NULL* ; q - q.next
            while (q != NULL) {
                while (p != NULL && p->next != NULL && p->next->val < q->val) {
                    p = p->next;
                }
                qRecord = q->next;
                q->next = p->next;
                p->next = q;

                p = dummyHead;
                q = qRecord;
            }
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0147_H
