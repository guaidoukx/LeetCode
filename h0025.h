//
// Created by 项雅丽 on 2019/12/7.
//

#ifndef LEETCODE_H0025_H
#define LEETCODE_H0025_H

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

namespace h0025 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if (k == 1 || head == NULL || head->next == NULL)
                return head;
            ListNode *dummmyHaad = new ListNode(-1);
            dummmyHaad->next = head;
            ListNode *preRecord = dummmyHaad, *preGo = head;
            ListNode *pre, *cur, *nex, *prehead;
            int cnt = 0;

            while (preGo != NULL) {
                // 遍历所有节点 计数
                cnt++;
                preGo = preGo->next;

                if (cnt == k) {
                    cnt = 0;
                    // 先记录一下 这k个节点中最前面的那个
                    prehead = preRecord->next;
                    pre = preRecord->next;
                    cur = preRecord->next->next;
                    // preGo这是时候已经遍历到了第k+1个，所以，cur==preGo的时候，cur和pre不需要翻转，这时候pre指向的是最后一个
                    while (cur != preGo) {
                        nex = cur->next;
                        cur->next = pre;
                        pre = cur;
                        cur = nex;
                    }
                    //            prehead                pre       cur
                    // preRecord ->  O  ->  O  ->  O  ->  O  ->  preGo
                    prehead->next = preGo;
                    preRecord->next = pre;
                    preRecord = prehead;
                }
            }
            return dummmyHaad->next;
        }
    };
}

#endif //LEETCODE_H0025_H
