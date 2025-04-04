#include <iostream>
#include <vector>

#include "linked_list.hpp"


ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* next, *prev;
    prev = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        if (!next) break;
        curr = next;
    }
    return curr;
}

int main() {
    struct ListNode* list1 = create_node(1);

    add_new_node(list1, 2);
    add_new_node(list1, 3);
    add_new_node(list1, 4);
    add_new_node(list1, 5);

    struct ListNode* ret;
    ret = reverseList(list1);
    dump_list(ret);

    free_list(&ret);

    return 0;
}
