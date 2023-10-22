//test_ArrayQueue.cpp
#include "ArrayQueue.h"
#include<iostream>

int main(void) {
    ArrayQueue queue;

    //Testing enqueue
    queue.enqueue("Item 1");
    queue.enqueue("Item 2");
    queue.enqueue("Item 3");
    queue.enqueue("Item 4");
    queue.enqueue("Item 5");
    queue.enqueue("Item 6");

    //Testing peek
    std::cout << "Peek: " << queue.peek() << std::endl;
    //Testing size
    std::cout << "Size: " << queue.size() << std::endl;
    //Testing empty
    if (queue.empty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        std::cout << "The queue is not empty." << std::endl;
    }
    std::cout << std::endl;

    std::cout<<"delete 1 Item"<<std::endl;
    //Testing dequeue
    queue.dequeue();
    //Testing peek
    std::cout << "Peek: " << queue.peek() << std::endl;
    //Testing size
    std::cout << "Size: " << queue.size() << std::endl;
    //Testing empty
    if (queue.empty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        std::cout << "The queue is not empty." << std::endl;
    }
    std::cout << std::endl;

    std::cout<<"delete all Item"<<std::endl;
    for(int i=0;i<5;i++){
        queue.dequeue();
    }
    //Testing peek
    std::cout << "Peek: " << queue.peek() << std::endl;
    //Testing size
    std::cout << "Size: " << queue.size() << std::endl;
    if (queue.empty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        std::cout << "The queue is not empty." << std::endl;
    }

    return 0;
}
