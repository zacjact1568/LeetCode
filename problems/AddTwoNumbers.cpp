//
// Created by Zack Zhang on 2018/5/3.
//

#include "AddTwoNumbers.h"

ListNode* AddTwoNumbers::solution(ListNode* l1, ListNode* l2) {
    auto current1 = l1;
    auto current2 = l2;
    int carry = 0;
    // Head node
    auto head = new ListNode(-1);
    auto current3 = head;
    while (current1 || current2) {
        int digitSum = (current1 ? current1->val : 0) + (current2 ? current2->val : 0) + carry;
        current3->next = new ListNode(digitSum < 10 ? digitSum : digitSum - 10);
        carry = digitSum < 10 ? 0 : 1;
        // Move three pointers to the next node
        if (current1) current1 = current1->next;
        if (current2) current2 = current2->next;
        current3 = current3->next;
    }
    // Now, current1 and current2 are both pointing to the next "node" of the rear node of two linked lists (Of course, this "node" doesn't exist)
    // If the last carry exists, one more node with value 1 is needed
    if (carry == 1) current3->next = new ListNode(1);
    // The next node of the head node is the start of the result linked list
    auto result = head->next;
    delete head;
    return result;
}

void AddTwoNumbers::test() {
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    AddTwoNumbers addTwoNumbers;
    auto result = addTwoNumbers.solution(l1, l2);
    clean(l1);
    clean(l2);
    clean(result);
}

void AddTwoNumbers::clean(ListNode* l) {
    if (l->next) clean(l->next);
    delete l;
}
