#include <iostream>
#include "ArrayQueue.h"

int main() {
    // Create an ArrayQueue object
    ArrayQueue queue1;
    queue1.enqueue("Item1");
    queue1.enqueue("Item2");
    queue1.enqueue("Item3");

    // Test the copy constructor
    ArrayQueue queue2 = queue1; // Use the copy constructor
    std::cout << "(original) queue1 size: " << queue1.size() << std::endl;
    std::cout << "(copy) queue2 size: " << queue2.size() << std::endl;

    // Test the assignment operator
    ArrayQueue queue3;
    queue3.enqueue("Item4");
    queue3.enqueue("Item5");
    queue3.enqueue("Item6");
    queue3.enqueue("Item7");
    queue3.enqueue("Item8");
    queue3 = queue1; // Use the assignment operator
    std::cout << "(original) queue1 size: " << queue1.size() << std::endl;
    std::cout << "(operator) queue3 size: " << queue3.size() << std::endl;

    return 0;
}
