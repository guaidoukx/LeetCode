//
// Created by 项雅丽 on 2019/12/4.
//

#ifndef LEETCODE_H0328_H
#define LEETCODE_H0328_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0328 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *oddEvenList(ListNode *head) {
            if (head==NULL || head->next==NULL || head->next->next==NULL)
                return head;

            ListNode *oddHead = new ListNode(0);
            oddHead->next = head;
            ListNode *evenHead = new ListNode(0);
            evenHead->next = head->next;

            ListNode *p = oddHead;
            ListNode *q = evenHead;
            ListNode *h = head;
            int cnt = 1;
            while (h!=NULL){
                if (cnt %2 ==1){
                    p->next = h;
                    p = p->next;
                    h=h->next;
                    cnt ++;
                } else{
                    q->next = h;
                    q = q->next;
                    h= h->next;
                    cnt++;
                }
            }
            q->next = NULL;
            p->next = evenHead->next;
            return oddHead->next;
        }
    };
}

#endif //LEETCODE_H0328_H
