#include "stack.h"
Stack::Stack(int n)
{
    size = n;
    pitems = new ItemSta[size];
    top = 0;
}
Stack::Stack(const Stack& st)
{
    size = st.size;
    pitems = new ItemSta[size];
    for (int i = 0; i < size; ++i)
        *(pitems + i) = *(st.pitems + i);

    top = st.top;
}
Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const ItemSta& item)
{
    if (top < size) {
        pitems[top++] = item;
        return true;
    } else
        return false;
}
bool Stack::pop(ItemSta& item)
{
    if (top > 0) {
        item = pitems[--top];
        return true;
    } else
        return false;
}

Stack& Stack::operator=(const Stack& st)
{
    size = st.size;
    pitems = new ItemSta[size];
    for (int i = 0; i < size; ++i)
        *(pitems + i) = *(st.pitems + i);

    top = st.top;
    return *this;
}