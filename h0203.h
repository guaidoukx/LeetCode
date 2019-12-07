//
// Created by 项雅丽 on 2019/12/4.
//

#ifndef LEETCODE_H0203_H
#define LEETCODE_H0203_H

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

namespace h0203 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *removeElements(ListNode *head, int val) {
            ListNode *dummyHead = new ListNode(-1);
            dummyHead->next = head;
            ListNode *q = dummyHead;

            // 不优雅的解法
            /*while ( q!=NULL && q->next != NULL) {
                while (q->next != NULL && q->next->val == val){
                    q->next = q->next->next;
                }q = q->next;
            }*/

            while ( q->next != NULL) {
                if (q->next->val == val){
                    q->next = q->next->next;
                    continue; // 这里的continue真是用的妙啊，既重新进入循环， 判断了q->next != NULL这个条件，又没有将q=q->next带入。
                }q = q->next;
            }

            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0203_H
