//
// Created by Ed Garcia on 10/10/23.
//

#include "arrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue()
{
    itemCount = 0;
    front = -1;
    back = -1;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType &newEntry)
{
    bool canQ = (itemCount < CAPACITY - 1);

    if (isEmpty())
    {
        back = front = 0;
        items[front] = newEntry;
    }

    else
    {
        back = (back + 1) % CAPACITY; 
        items[back] = newEntry;
    }

    itemCount++;
    
    return canQ;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
    bool canDQ = itemCount > -1;

    if (canDQ)
    {
        front = (front + 1) % CAPACITY;
        itemCount--;
    }
    return canDQ;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if(!isEmpty())
    {
        return items[front];
    }
    return 0;
}
