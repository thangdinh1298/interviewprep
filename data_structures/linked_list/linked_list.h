#pragma once

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* linked_list_from_vector(const std::vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tmp = nullptr;

    for(const auto n : v) {
        if (!head) {
            head = new ListNode(n);
            tmp = head;
        } else {
            tmp->next = new ListNode(n);
            tmp = tmp->next;
        }
    }
    return head;
}

void print(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << '\n';
}
