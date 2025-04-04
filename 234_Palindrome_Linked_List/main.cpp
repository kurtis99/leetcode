#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

#include "linked_list.hpp"

using namespace std;


bool isPalindrome2(ListNode* head) {
    ListNode* fast              = head;
    ListNode* slow_lo, *slow_hi;
    ListNode* slow_lo_prev = nullptr;

    slow_lo = head;

    while (fast) {
        slow_lo_prev = slow_lo;
        slow_lo = slow_lo->next;
        if (fast->next == nullptr) {
            // slow is the center and size of the list is odd number
            slow_hi = slow_lo->next;
            slow_lo = slow_lo_prev;
            break;
        }
        fast = fast->next;
        if (fast->next == nullptr) {
            // ew have even number of elements in the list size
            slow_hi = slow_lo;
            slow_lo = slow_lo_prev;
            break;
        }
        fast = fast->next;
    }

    // reverse lower sublist
    ListNode* curr        = head;
    ListNode* prev, *next = head;
    prev = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        if (curr == slow_lo) break;
        prev = curr;
        if (next == nullptr) break;
        curr = next;
    }

    // compare two lists
    while (slow_lo) {
        if (slow_lo->val != slow_hi->val)
            return false;
        slow_lo = slow_lo->next;
        slow_hi = slow_hi->next;
    }
    return true;
}


bool isPalindrome(ListNode* head) {
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    while(temp1->next && temp1->next->next){
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }
    ListNode* curr = temp2->next;
    ListNode* prev = nullptr;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    while(prev && head){
        if(prev->val != head->val) return false;
        prev = prev->next;
        head = head->next;
    }
    return true;
}


int getDecimalValue(ListNode* head) {
    ListNode* curr = head;

    int val = 0;
    while (curr) {
        val |= curr->val & 1;
        val  = val << 1;
        curr = curr->next;
    }
    return val;
}


int main() {
    
    struct ListNode* list = create_node(1);

    add_new_node(list, 0);
    add_new_node(list, 1);
//    add_new_node(list, 1);



    int ret;
    ret = getDecimalValue(list);
    cout << ret << endl;


    ret = isPalindrome(list);
//    dump_list(ret);

    cout << ret << endl;

    free_list(&list);



    return 0;
}
