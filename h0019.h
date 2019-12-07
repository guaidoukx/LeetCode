//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0019_H
#define LEETCODE_H0019_H

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

namespace h0019 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *dummyHead = new ListNode(-1);
            dummyHead->next = head;
            ListNode *p = dummyHead, *q = dummyHead;
            int cnt = 0;
            while (cnt <= n & p != NULL) {
                cnt++;
                p = p->next;
            }
            while (p != NULL) {
                p = p->next;
                q = q->next;
            }
            q->next = q->next->next;
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0019_H
