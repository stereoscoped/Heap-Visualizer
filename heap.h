#ifndef HEAP_H
#define HEAP_H

// All heaps are either min heaps or max heaps
enum HeapType {
    MIN_HEAP,
    MAX_HEAP,
    UNSPECIFIED
};

class Heap {
    public:

        // All heaps are given an ordering rule
        Heap(HeapType type) : m_type(type) {}
        virtual ~Heap() = default;

        // All heaps need insertion, pop, peak, and can check if empty
        virtual void insert(int) = 0;
        virtual void pop() = 0;
        virtual int peek() const = 0;
        virtual bool empty() const = 0;
        HeapType getPriorityType() const { return m_type; }

    protected:
        HeapType m_type;
};

#endif