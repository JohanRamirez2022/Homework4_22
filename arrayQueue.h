// array.h
// Header file and Specification for arrayQueue.cpp
// Derived from queue.h for queue functions

#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.h"

template<class ItemType>
class ArrayQueue: public QueueInterface<ItemType>
{

protected:
    static const int CAPACITY = 100;
    int itemCount;
    int front;
    int back;
    ItemType items[CAPACITY];
    int queue;

public:
    ArrayQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;

    ~ArrayQueue(){}
};

#include "arrayQueue.cpp"
#endif //ARRAY_QUEUE
