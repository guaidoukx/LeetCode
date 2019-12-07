//
// Created by 项雅丽 on 2019/12/4.
//

#ifndef LEETCODE_H0445_H
#define LEETCODE_H0445_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <stack>

using namespace std;

namespace h0445 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            stack<int> s1, s2;
            while (l1 != NULL) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            while (l2 != NULL) {
                s2.push(l2->val);
                l2 = l2->next;
            }

            ListNode *dummyHead = new ListNode(-1);
            ListNode *cur = NULL;
            int jin = 0, n1 = 0, n2 = 0, sum = 0;
            while (!s1.empty() || !s2.empty() || jin) {
                if (s1.empty()) n1 = 0;
                else {
                    n1 = s1.top();
                    s1.pop();
                }

                if (s2.empty()) n2 = 0;
                else {
                    n2 = s2.top();
                    s2.pop();
                }

                sum = n1 + n2 + jin;
                jin = sum / 10;
                cur = new ListNode(sum % 10);
                cur->next = dummyHead->next;
                dummyHead->next = cur;
            }
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0445_H
