#include "arrayheap.h"
#include <iostream>

/*

TEMPORARY TEST FILE, WILL BE CHANGED EVENTUALLY

*/

int main () {
    ArrayHeap myheap(MIN_HEAP);
    std::cout << myheap.getPriorityType() << std::endl;
    for (int i = 0; i < 5; ++i) {
        int input;
        std::cin >> input;
        myheap.insert(input);

        myheap.print();
        std::cout << std::endl;
    }

    std::cout << "REEE" << std::endl;
    myheap.print();
}