//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0069_H
#define LEETCODE_H0069_H

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

namespace h0069 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode *p = head;
            int n = 1;
            while (p != NULL && p->next != NULL) {
                p = p->next;
                n++;
            }
            p->next = head;
            k = k % n;

            p = head;
            int cnt = 1;
            while (cnt < n - k) {
                p = p->next;
                cnt++;
            }
            ListNode *res = p->next;
            p->next = NULL;
            return res;
        }
    };
}

#endif //LEETCODE_H0069_H
