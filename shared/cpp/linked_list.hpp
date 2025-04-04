#pragma once
#include <iostream>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_node(int val);
void add_new_node(struct ListNode* head, int val);
void free_list(struct ListNode** head);
void dump_list(struct ListNode* head);
