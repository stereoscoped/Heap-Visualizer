#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include "heap.h"
#include <vector>

class ArrayHeap : public Heap {
    public:
        ArrayHeap(HeapType = UNSPECIFIED);

        void insert(int) override;
        void pop() override;
        int peek() const override;
        bool empty() const override;
    private:
        std::vector<int> m_heap;
};

#endif
