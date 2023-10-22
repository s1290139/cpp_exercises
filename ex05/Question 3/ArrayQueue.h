// ArrayQueue.h

#include <string>
#include <iostream>

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

class ArrayQueue {
private:
    int _num_items; // number of items in the queue
    int _allocated_size; // size of memory allocated
    int _first; // index to the first element of the queue 
    int _last; // index of the next available slot 
    std::string* _items; // container 
    
    void resize(int max_size) {
        if (max_size == 0) max_size++;

        // Move stack to a new array of size max
        std::string* temp = new std::string[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[(_first + i) % _allocated_size];
        }
        delete[] _items;
        _items = temp;

        _first = 0; 
        _last = _num_items;
        _allocated_size = max_size;
    }

public:
    // Constructors:
    // Default constructor 
    ArrayQueue() : _num_items(0), _allocated_size(1), _first(0), _last(0), _items(new std::string[1]) {}

    /*// copy con
    ArrayQueue(const ArrayQueue& a) : _num_items(a._num_items), _allocated_size(a._allocated_size), _first(a._first), _last(a._last), _items(new std::string[a._allocated_size]) {
        for (int i = 0; i < _num_items; ++i) {
            _items[i] = a._items[(_first + i) % _allocated_size];
        }
    }*/

    // move con
    ArrayQueue(ArrayQueue&& a) noexcept
        : _num_items(a._num_items), _allocated_size(a._allocated_size), _first(a._first), _last(a._last), _items(a._items) {
        a._num_items = 0;
        a._allocated_size = 0;
        a._first = 0;
        a._last = 0;
        a._items = nullptr;
    }



    // move operator
    ArrayQueue& operator=(ArrayQueue&& b) noexcept {
    if (this == &b) {
        return *this;
    }
    delete[] _items;
    _num_items = b._num_items;
    _allocated_size = b._allocated_size;
    _first = b._first;
    _last = b._last;
    _items = b._items;

    b._num_items = 0;
    b._allocated_size = 0;
    b._first = 0;
    b._last = 0;
    b._items = nullptr;

    return *this;
}

    /*// assignment operator
    ArrayQueue& operator=(const ArrayQueue& b) {
        if (this == &b) {
            return *this;
        }
        _num_items = b._num_items;
        _allocated_size = b._allocated_size;
        _first = b._first;
        _last = b._last;

        delete[] _items;
        _items = new std::string[b._allocated_size];
        for (int i = 0; i < _num_items; ++i) {
            _items[i] = b._items[(_first + i) % _allocated_size];
        }

        return *this;
    }*/


    explicit ArrayQueue(int allocated_size) : _num_items(0), _allocated_size(allocated_size), _first(0), _last(0), _items(new std::string[allocated_size]) {}

    // Destructor:
    ~ArrayQueue() {
        delete[] _items;
    }

    // Add an item to the queue 
    void enqueue(const std::string& item) {
        if (_num_items == _allocated_size) resize(2 * _allocated_size);
        _items[_last++] = item; 
        if (_last == _allocated_size) _last = 0; // wrap 
        _num_items++; 
    }

    // Remove the item that was least recently added 
    void dequeue() {
        _num_items--;
        _first++; 
        if (_first == _allocated_size) _first = 0; // wrap 
        if (_num_items > 0 && _num_items == _allocated_size / 4) resize(_allocated_size / 2);
    }

    // Access the top-most item 
    std::string peek() {
        return _items[_first];
    }

    // Check if the stack is empty 
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack 
    int size() const { return _num_items; }
};

#endif // ARRAY_QUEUE_H
