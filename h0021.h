//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0021_H
#define LEETCODE_H0021_H

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

namespace h0021 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode *dummyHead = new ListNode(-1);
            ListNode *p = dummyHead;

            while (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            while (l1!=NULL){
                p->next = l1;
                l1=l1->next;
                p = p->next;
            }
            while (l2!=NULL){
                p->next = l2;
                l2 = l2->next;
                p=p->next;
            }
            p->next = NULL;
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0021_H
