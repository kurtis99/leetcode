#include <iostream>

#include "linked_list.hpp"

using namespace std;

struct ListNode* create_node(int val) {
    struct ListNode* node;
    node = new ListNode();
    node->val = val;
    node->next = nullptr;
    return node;
}

// Go to tail and add new node there
void add_new_node(struct ListNode* head, int val) {
    // find tail
    struct ListNode* node = head;;
    while (node->next != nullptr) {
        node = node->next;
    }
    struct ListNode* new_list;
    new_list        = new ListNode();
    new_list->val   = val;
    new_list->next  = nullptr;
    node->next = new_list;
}

void free_list(struct ListNode** head) {
    struct ListNode* node = *head;;
    while (node && node->next != nullptr) {
        struct ListNode* curr = node;
        struct ListNode* next = node->next;
        delete curr;
        node = next;
    }
    delete node;
    *head = nullptr;
}

void dump_list(struct ListNode* head) {
    struct ListNode* node = head;;
    while (node->next != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << node->val << endl;
}
