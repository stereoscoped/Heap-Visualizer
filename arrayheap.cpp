#include "arrayheap.h"
#include <algorithm>
#include <iostream> // toberemoved

ArrayHeap::ArrayHeap(HeapType type) : Heap(type) {}

void ArrayHeap::insert(int value) {
    m_heap.push_back(value);

    int current = m_heap.size() - 1;

    while (current > 0) {
        int parent = (current - 1) / 2;

        // Compare current with parent
        // Swap if needed

        current = parent;
    }
}

void ArrayHeap::pop() {
    return;
}
int ArrayHeap::peek() const {
    return 1;
}
bool ArrayHeap::empty() const {
    return false;
}

int main () {
    ArrayHeap myheap;
    std::cout << myheap.getPriorityType() << std::endl;
}