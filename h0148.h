//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0148_H
#define LEETCODE_H0148_H

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

namespace h0148 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            return partition(head);
        }

        ListNode *partition(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            // 快慢指针找中点
            ListNode *p = head, *q = head;
            while (true) {
                if (p->next == NULL) { // 因为是break了，并不回继续再找，所以不会出现 p==NULL 但是p.next！=NULL的情况。
                    break;
                } else if (p->next->next == NULL) {
                    break;
                } else {
                    p = p->next->next;
                    q = q->next;
                }
            }
            ListNode *l, *r;
            r = partition(q->next);
            q->next = NULL; //  中间可一定要断开呀！
            l = partition(head);

            return merge(l, r);
        }

        ListNode *merge(ListNode *l, ListNode *r) {
            ListNode *dummyHead = new ListNode(-1);
            ListNode *p = dummyHead;
            while (l != NULL && r != NULL) {
                if (l->val < r->val) {
                    p->next = l;
                    p = p->next;
                    l = l->next;
                } else {
                    p->next = r;
                    p = p->next;
                    r = r->next;
                }
            }
            while (l != NULL) {
                p->next = l;
                p = p->next;
                l = l->next;
            }
            while (r != NULL) {
                p->next = r;
                p = p->next;
                r = r->next;
            }
            p->next = NULL;
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0148_H
