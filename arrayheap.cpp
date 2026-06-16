#include "arrayheap.h"
#include <algorithm>

ArrayHeap::ArrayHeap(HeapType type) : Heap(type) {}

void ArrayHeap::insert(int value) {

    // Add new value to the end of the heap
    m_heap.push_back(value);

    // From the inserted node, iterate
    int current = m_heap.size() - 1;

    if (m_type == MIN_HEAP) {

        while (current != 0 &&
               m_heap[current] < m_heap[(current - 1) / 2]) {

            // Calculate the parent's index
            int parent = (current - 1) / 2;

            std::swap(m_heap[current], m_heap[parent]);
            current = parent;
        }
    }

    else if (m_type == MAX_HEAP) {

        while (current != 0 &&
               m_heap[current] > m_heap[(current - 1) / 2]) {

            // Calculate the parent's index
            int parent = (current - 1) / 2;

            std::swap(m_heap[current], m_heap[parent]);
            current = parent;
        }
    }

    else {
        return;
    }
}

void ArrayHeap::pop() {

    // Returns if empty
    if (empty()) {
        return;
    }

    // If only one element exists, remove it
    if (m_heap.size() == 1) {
        m_heap.pop_back();
        return;
    }

    // Move the last value to the root and remove the duplicate
    m_heap[0] = m_heap.back();
    m_heap.pop_back();

    // From the root node, iterate
    int current = 0;

    while (true) {

        // Calculate the children's indices
        int left = 2 * current + 1;
        int right = 2 * current + 2;

        int target = current;

        if (m_type == MIN_HEAP) {

            // Find the smallest value among parent and children
            if (left < m_heap.size() &&
                m_heap[left] < m_heap[target]) {

                target = left;
            }

            if (right < m_heap.size() &&
                m_heap[right] < m_heap[target]) {

                target = right;
            }
        }

        else if (m_type == MAX_HEAP) {

            // Find the largest value among parent and children
            if (left < m_heap.size() &&
                m_heap[left] > m_heap[target]) {

                target = left;
            }

            if (right < m_heap.size() &&
                m_heap[right] > m_heap[target]) {

                target = right;
            }
        }

        // Stop when the heap property is restored
        if (target == current) {
            return;
        }

        std::swap(m_heap[current], m_heap[target]);
        current = target;
    }
}

int ArrayHeap::peek() const {

    // Returns -1 if empty and the first index otherwise
    if (empty()) {
        return -1;
    }

    return m_heap[0];
}

bool ArrayHeap::empty() const {

    // Checks if empty
    return m_heap.empty();
}

int ArrayHeap::size() const {
    return m_heap.size();
}

/* 
LIKELY TO BE REMOVED AT ANOTHER TIME
*/
void ArrayHeap::print() const {

    // Prints the heap array in level-order (array form)
    for (int i = 0; i < m_heap.size(); i++) {
        std::cout << m_heap[i] << " ";
    }

    std::cout << std::endl;
}