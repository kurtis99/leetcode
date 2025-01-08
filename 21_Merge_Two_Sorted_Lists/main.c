#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if (list1 == NULL || list2 == NULL) {
        return list1 == NULL ? list2 : list1;
    }
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    struct ListNode* ret, *head;

    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    ret = head;
    do {
        if (list1 == NULL) {
            ret->next = list2;
            break;
        }
        if (list2 == NULL) {
            ret->next = list1;
            break;
        }
        if (list1->val <= list2->val) {
            ret->next = list1;
            list1 = list1->next;
        } else {
            ret->next = list2;
            list2 = list2->next;
        } 
        ret = ret->next;
    } while (true);


    return head;
}



/* Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]  */

static struct ListNode* create_node(int val) {
    struct ListNode* node;
    node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Go to tail and add new node there
static void add_new_node(struct ListNode* head, int val) {
    // find tail
    struct ListNode* node = head;;
    while (node->next != NULL) {
        node = node->next;
    }
    struct ListNode* new;
    new = malloc(sizeof(struct ListNode));
    new->val   = val;
    new->next  = NULL;
    node->next = new;
}

static void free_list(struct ListNode** head) {
    struct ListNode* node = *head;;
    while (node && node->next != NULL) {
        struct ListNode* curr = node;
        struct ListNode* next = node->next;
        free(curr);
        node = next;
    }
    free(node);
    *head = NULL;
}

static void dump_list(struct ListNode* head) {
    struct ListNode* node = head;;
    while (node->next != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
}

int main() {
    struct ListNode* list1 = create_node(1);
    struct ListNode* list2 = create_node(1);

    add_new_node(list1, 2);
    add_new_node(list1, 4);

    add_new_node(list2, 3);
    add_new_node(list2, 4);

    struct ListNode* ret;
    ret = mergeTwoLists(list1, list2);
    dump_list(ret);

    free_list(&ret);

    return 0;
}
