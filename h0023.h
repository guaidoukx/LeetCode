//
// Created by 项雅丽 on 2019/12/19.
//

#ifndef LEETCODE_H0023_H
#define LEETCODE_H0023_H

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

namespace h0023 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };


    class Solution {
    public:
        struct cmp {
            bool operator()(ListNode *a, ListNode *b) {    //通过传入不同类型来定义不同类型优先级
                return a->val > b->val;    //最小值优先
            }
        };

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            // 最小、最大要搞清楚啊
            priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
            ListNode *dummyHead = new ListNode(0);
            ListNode *p = dummyHead;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    pq.push(lists[i]);
                }

            }
            while (!pq.empty()) {
                ListNode *tmp = pq.top();

                pq.pop();
                if (tmp->next != NULL)
                    pq.push(tmp->next);
                p->next = tmp;
                p = p->next;
            }
            p->next = NULL;
            return dummyHead->next;
        }
    };
}

#endif //LEETCODE_H0023_H
