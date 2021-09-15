#include "queue.h"

#include <iostream>
using namespace std;

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

Queue::Queue(int qs) : qsize(qs)
{
    front = nullptr;
    rear = nullptr;
    items = 0;
}
Queue::~Queue()
{
    Node *temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
        // --items;
    }
}
bool Queue::isempty() const
{
    return (items == 0);
}
bool Queue::isfull() const
{
    return (items >= qsize);
}
int Queue::queuecount() const
{
    return items;
}
bool Queue::enqueue(const ItemCus &item)
{
    if (isfull())
        return false;
    Node *add = new Node{item, nullptr};
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    ++items;
    return true;
}
bool Queue::dequeue(ItemCus &item)
{
    if (isempty())
        return false;
    Node *temp = front;
    item = front->item;
    front = front->next;
    delete temp;
    --items;
    if (front == nullptr)
    // if(items == 0)
        rear = nullptr;
    return true;
}