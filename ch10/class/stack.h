#ifndef STACK_H_
#define STACK_H_
//模板类或者含有模板成员函数的类 实现和声明需要在同一个文件中。
// typedef int T;
template <class T>
class Stack {
   private:
    const static int MAX = 10;
    T items[MAX];
    int top;

   public:
    Stack() { top = 0; };
    bool isempty() { return top == 0; };
    bool isfull() { return top == MAX; };
    bool push(const T &item);
    bool pop(T &item);
};

template <class T>
bool Stack<T>::push(const T &item)
{
    if (isfull())
        return false;
    items[top++] = item;
    return true;
}
template <class T>
bool Stack<T>::pop(T &item)
{
    if (isempty())
        return false;
    item = items[--top];
    return true;
}

#endif