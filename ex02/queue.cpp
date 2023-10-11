//s1290139
#include "queue.h"
#include <iostream>

bool Queue::empty(){return _num_items == 0;}

bool Queue::full(){return _num_items == _max_size;}

int Queue::size(){return _num_items;}

void Queue::enqueue(Point point){
    if(full()){
        _first=(_first+1)% _max_size;
    }
    _items[_last]=point;
    _last=(_last+1)%_max_size;
    _num_items++;
}

void Queue::dequeue(){
    _first=(_first+1)%_max_size;
    _num_items--;
}

Point Queue::peek(){
    return _items[_first];
}


