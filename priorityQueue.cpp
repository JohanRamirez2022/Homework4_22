#include "priorityQueue.h"

template<class ItemType>
bool PriorityQueue<ItemType>::push(const ItemType& newEntry)
{
    bool canPush = (this->itemCount < this->CAPACITY - 1);

    if (canPush)
    {
        if (this->isEmpty())
        {
            this->enqueue(newEntry);
        }
        else
        {
            ArrayQueue<ItemType> temp;

            while (!this->isEmpty() && newEntry > this->peekFront())
            
            {
                temp.enqueue(this->peekFront());
                this->dequeue();
            }

            temp.enqueue(newEntry);

            while (!this->isEmpty())
            {
                temp.enqueue(this->peekFront());
                this->dequeue();
            }
            
            while (!temp.isEmpty())
            {
                this->enqueue(temp.peekFront());
                temp.dequeue();
            }
        }
    }
    return canPush;
}