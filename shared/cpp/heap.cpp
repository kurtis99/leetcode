#include <iostream>

#include "heap.hpp"

void MinHeap::add(int value) {
    h.push_back(value);
    if (hasParent(h.size() - 1))
        shiftUp(h.size() - 1);
}

int MinHeap::pop(int value) {
    // Search for value
    int ret = 0, idx;
    for (idx = 0; idx < h.size(); idx++) {
        if (h[idx] == value) {
            ret = h[idx];
            break;
        }
    }
    if (idx >= h.size()) return 0;

    swap(idx, h.size() - 1);
    h.resize(h.size() - 1);
    if (hasParent(idx) && (h[idx] > parent(idx)))
        shiftDown(idx);
    else
        shiftUp(idx);

    return ret;
}

int MinHeap::getMin() {
    return h[0];
}

int MinHeap::popMin() {
    int ret = h[0];
    swap(0, h.size() - 1);
    shiftDown(0);
    h.resize(h.size() - 1);
    return ret;
}

void MinHeap::shiftUp(int index) {
    int idx = index;
    while (hasParent(idx)) {
        if (parent(idx) > h[idx]) {
            swap(idx, getParent(idx));
            idx = getParent(idx);
        } else {
            break;
        }
    }
}

void MinHeap::shiftDown(int index) {
    int idx = index;
    
    int swap_idx = 0;
    if (hasLeft(idx) && hasRight(idx)) {
        if (leftChild(idx) < rightChild(idx)) {
            swap_idx = getLeft(idx);
        } else {
            swap_idx = getRight(idx);
        }
    } else if (hasLeft(idx)) {
        swap_idx = getLeft(idx);
    } else if (hasRight(idx)) {
        swap_idx = getRight(idx);
    } else {
        return;
    }

    swap(idx, swap_idx);
    shiftDown(swap_idx);
}

void MinHeap::heapify(vector<int>& arr) {
    
}

void MinHeap::print_at_idx(int idx) {

}

void MinHeap::print() {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
