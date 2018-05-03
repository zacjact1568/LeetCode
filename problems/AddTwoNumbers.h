//
// Created by Zack Zhang on 2018/5/3.
//

#ifndef LEETCODE_ADDTWONUMBERS_H
#define LEETCODE_ADDTWONUMBERS_H

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNumbers {

private:

    ListNode* solution(ListNode* l1, ListNode* l2);

    static void clean(ListNode* l);

public:

    static void test();
};

#endif //LEETCODE_ADDTWONUMBERS_H
