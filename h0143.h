//
// Created by 项雅丽 on 2019/11/28.
//

#ifndef LEETCODE_H0143_H
#define LEETCODE_H0143_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0143 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        void reorderList(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return;

            //  找到中点，并知道正负
            bool odd = false;
            ListNode *mid = NULL;
            ListNode *p = head, *q = head;
            while (q != NULL) {
                p = p->next;
                if (q->next == NULL) {
                    mid = p;
                    odd = true;
                    break;
                } else if (q->next->next == NULL) {
                    mid = p;
                    odd = false;
                    break;
                } else {
                    q = q->next->next;
                }
            }

            // 反转链表
            ListNode *pre = NULL;
            ListNode *cur = mid;
            ListNode *nex;
            while (cur != NULL) {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            q = pre;

            // 最后过程
            p = head;
            ListNode *res = new ListNode(0);
            ListNode *toreturn = res;
            while (q != NULL) {
                res->next = p;
                p = p->next;
                res = res->next;
                res->next = q;
                q = q->next;
                res = res->next;
            }
            if (p != NULL && odd == true) {
                res->next = p;
                res = res->next; // 不知道为什么一定要加上这两句 不然不行。
            }
            res->next = NULL; // 不知道为什么一定要加上这两句 不然不行。

            head = toreturn->next;
            return;
        }
    };

}

// https://leetcode-cn.com/problems/reorder-list/solution/c-san-chong-jie-fa-by-lyh131201/
// 更优美的写法
#endif //LEETCODE_H0143_H
