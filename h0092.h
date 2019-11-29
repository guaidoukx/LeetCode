//
// Created by 项雅丽 on 2019/11/28.
//

#ifndef LEETCODE_H0092_H
#define LEETCODE_H0092_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <numeric>

using namespace std;

namespace h0092 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            int count = 1;

            ListNode* preRecord = new ListNode(0); // 设置一个虚拟头节点来防止要一直换到末尾的情况
            preRecord->next= head;
            ListNode* postPecord= NULL;
            ListNode* FinalHead = preRecord; // 最终这个地方是不动的，是虚拟头节点，用来返回虚拟头节点的下一个节点。

            ListNode* pre = NULL;
            ListNode* cur = head;
            ListNode* nex;

            while (count < m){ // 先遍历到m节点
                preRecord = cur;
                cur = cur->next;
                count ++;
            }
            postPecord = cur;
            while (count<n+1 && cur!=NULL){ // 开始反转
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
                count++;
            }
            // 连接上三部分
            postPecord->next = cur;
            preRecord->next = pre;

            delete preRecord;
            return FinalHead->next;
        }
    };
}

#endif //LEETCODE_H0092_H
