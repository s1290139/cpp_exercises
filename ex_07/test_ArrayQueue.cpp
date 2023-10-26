//test_ArrayQueue.cpp
#include "ArrayQueue.h"
#include<iostream>

int main(){

    //test full empty
    /*ArrayQueue enq(5);
    for(int i=0;i<10;i++){
        enq.enqueue("qqq");
    }*/

    //test empty
    ArrayQueue emq(5);
    for(int i=0;i<5;i++){
        emq.enqueue("qqq");
    }
    for(int i=0;i<5;i++){
        emq.dequeue();
    }

    return 0;
}
