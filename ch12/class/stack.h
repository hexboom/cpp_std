#ifndef STACK_H_
#define STACK_H_

typedef int ItemSta;

class Stack {
   private:
    enum { MAX = 10 };  // constant specific to class
    ItemSta *pitems;       // holds stack items
    int size;
    int top;  // index for top stack item
   public:
    Stack(int n = MAX);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const ItemSta &item);  // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(ItemSta &item);  // pop top into item
    Stack &operator=(const Stack &st);
};
#endif