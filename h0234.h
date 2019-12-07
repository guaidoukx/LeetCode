//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0234_H
#define LEETCODE_H0234_H

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

namespace h0234 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        bool isPalindrome(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return true;

            ListNode *p = head, *q = head;
            while (true) {
                if (p->next == NULL || p->next->next == NULL)
                    break;
                p = p->next->next;
                q = q->next;
            }
            ListNode *record = q->next; // 得到中点，并记录后面的部分。
            q->next = NULL;
            // 翻转后面部分的链表
            ListNode *pre = NULL, *cur = record, *nex;
            while (cur != NULL) {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            // 比较值
            p = head;
            while (p != NULL && pre != NULL) {
                if (p->val != pre->val)
                    return false;
                p =p->next;
                pre = pre->next;
            }
            return true;
        }
    };
}

// o ->  o -> o -> o -> NULL         p.next.next ==NULL 从head开始，这样是偶数个节点
//       q    p
// o ->  o -> o -> o -> o -> NULL  p.next ==NULL 从head开始，这样是奇数个节点
//            q         p

#endif //LEETCODE_H0234_H
