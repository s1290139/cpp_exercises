#include "ArrayQueue.h"
#include <iostream>

int main(void) {
    ArrayQueue queue;

    // Test enqueue
    queue.enqueue("Item 1");
    queue.enqueue("Item 2");
    queue.enqueue("Item 3");
    queue.enqueue("Item 4");
    queue.enqueue("Item 5");
    //previous
    std::cout << "Queue size: " << queue.size() << std::endl;

    // Test peek
    std::cout << "Peek: " << queue.peek() << std::endl;

    // Test dequeue
    queue.dequeue();
    std::cout << "Dequeue" << std::endl;

    // Test size
    std::cout << "Queue size: " << queue.size() << std::endl;

    // Test peek
    std::cout << "Peek: " << queue.peek() << std::endl;

    // Test empty
    if (queue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    queue.dequeue();
    std::cout << "Dequeue" << std::endl;
    queue.dequeue();
    std::cout << "Dequeue" << std::endl;
    queue.dequeue();
    std::cout << "Dequeue" << std::endl;
    queue.dequeue();
    std::cout << "Dequeue" << std::endl;
    if (queue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }



    return 0;
}
