#include <iostream>
#include <vector>

#include "linked_list.h"

//https://leetcode.com/problems/add-two-numbers/
ListNode* add_two_number(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    int carry = 0;
    while (l1 || l2) {
        //Calculate digit
        int digit = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = digit / 10;
        digit = digit % 10;

        //Add to result list
        if (!head) {
            head = new ListNode(digit);
            cur = head;
        } else {
            cur->next = new ListNode(digit);
            cur = cur->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry) {
        cur->next = new ListNode(1);
    }
    return head;
}

int main() {
    ListNode* l1 = linked_list_from_vector({9});
    ListNode* l2 = linked_list_from_vector({1});
    print(add_two_number(l1, l2));

    l1 = linked_list_from_vector({0});
    l2 = linked_list_from_vector({0});
    print(add_two_number(l1, l2));

    l1 = linked_list_from_vector({0, 1, 3});
    l2 = linked_list_from_vector({0});
    print(add_two_number(l1, l2));
}
