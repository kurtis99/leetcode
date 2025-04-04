#pragma once

#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> h;

    void swap(int index_a, int index_b) {
        int tmp = h[index_a];
        h[index_a] = h[index_b];
        h[index_b] = tmp;
    };

public:
    MinHeap() {};

    int getLeft(int parentIndex)  {return parentIndex * 2 + 1;};
    int getRight(int parentIndex) {return parentIndex * 2 + 2;}; 
    int getParent(int childIndex) {return (childIndex - 1) / 2;};

    bool hasLeft(int index)   {return getLeft(index) < h.size(); }
    bool hasRight(int index)  {return getRight(index) < h.size(); }
    bool hasParent(int index) {return getRight(index) >= 0; }

    int leftChild(int index)  {return h[getLeft(index)]; }
    int rightChild(int index) {return h[getRight(index)]; }
    int parent(int index)     {return h[getParent(index)]; }

    void add(int value);
    int  pop(int value);
    int getMin();
    int popMin();
    void shiftUp(int index);
    void shiftDown(int index);

    void heapify(vector<int>& arr);
    void print();
};
