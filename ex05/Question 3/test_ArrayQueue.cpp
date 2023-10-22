#include <iostream>
#include "ArrayQueue.h"

int main() {
    // Create an ArrayQueue object
    ArrayQueue queue1;
    queue1.enqueue("Item1");
    queue1.enqueue("Item2");
    queue1.enqueue("Item3");

    std::cout << "queue1 size before move: " << queue1.size() << std::endl;
    // Test the move constructor
    ArrayQueue queue2 = std::move(queue1);
    std::cout << "queue1 size after move: " << queue1.size() << std::endl;
    std::cout << "queue2 size after move: " << queue2.size() << std::endl;

    // Create another ArrayQueue object
    ArrayQueue queue3;
    queue3.enqueue("Item4");
    queue3.enqueue("Item5");

    // Test the move assignment operator
    queue3 = std::move(queue2);
    std::cout << "queue2 size after move assignment: " << queue2.size() << std::endl;
    std::cout << "queue3 size after move assignment: " << queue3.size() << std::endl;

    return 0;
}
