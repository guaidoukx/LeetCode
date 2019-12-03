//
// Created by 项雅丽 on 2019/12/1.
//

#ifndef LEETCODE_H0086_H
#define LEETCODE_H0086_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0086 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode *dummyHead1 = new ListNode(0);
            ListNode *dummyHead2 = new ListNode(0);

            ListNode *p1 = dummyHead1, *p2 = dummyHead2;
            ListNode *p = head;
            while (p != NULL) {
                if (p->val < x) {
                    p1->next = p;
                    p1 = p1->next;
                }
                else {
                    p2->next = p;
                    p2 = p2->next;
                }
                p = p->next;
            }
            p1->next = NULL;
            p2->next = NULL;

            p1->next = dummyHead2->next;
            return dummyHead1->next;
        }

    };
}

#endif //LEETCODE_H0086_H
