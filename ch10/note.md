# 对象和类 CH10 #
## 1. 构造函数 ##
1.1 列表初始化  
如果使用列表初始化，初始化参数必须严格匹配，不能进行隐式类型转换。
``` cpp
P::P(int ain = -1, const std::string &bin = "NULL")
{
    a = ain;
    b = bin;
}

P p3 {11,"p3 here"};        //right
P p3 {11.11,"p3 here"};     //wrong

```

1.2 默认构造函数  
仅当**没有任何构造函数**时编译器才提供默认构造函数。  
如果有带默认参数的构造函数，该构造函数可以被用作默认构造函数。
``` cpp
P::P(int ain, const std::string &bin);

P p1;   //wrong: 类P不存在默认构造函数

```

1.3 赋值初始化  
```cpp
P p2 = P(10.1, "p2 here");
```
这种初始化是否使用拷贝构造函数由编译器实现决定。

1.4 对象数组
```cpp
P pArray[3] = {
    {31, "pArray1 here"},
    P(32, "pArray2 here")};
std::cout << "=====test of pointer=====\n";
pArray->PrintP();
(pArray + 1)->PrintP();
pArray[2].PPP();
std::cout << "=====test of range-for=====\n";
for (auto p : pArray)
    p.PrintP();
std::cout << "---reference---\n";
for (auto &p : pArray)
    p.PrintP();
std::cout << "=====end of code block=====\n";

```
输出结果
```cmd
=====test of pointer=====
a = 31  b = pArray1 here
a = 32  b = pArray2 here
a = -1  b = NULL
=====test of range-for=====
a = 31  b = pArray1 here
delete pArray1 here
a = 32  b = pArray2 here
delete pArray2 here
a = -1  b = NULL
delete NULL
---reference---
a = 31  b = pArray1 here
a = 32  b = pArray2 here
a = -1  b = NULL
=====end of code block=====
delete NULL
delete pArray2 here
delete pArray1 here
End test
```
1.5 模板类或者含有模板成员函数的类  
模板类或者含有模板成员函数的类，实现和声明需要在同一个文件中。例子见stack.h中的实现。  

1.6 一次声明多个变量 如何初始化  
```cpp
//right
Move m2(2.3, 5.4), m3(1.2, 10.2);
Move m2 = {2.3, 5.4}, m3{1.2, 10.2};
Move m2 {2.3, 5.4}, m3{1.2, 10.2};
//wrong
Move m2, m3 = {(2.3, 5.4), (1.2, 10.2)};
```

1.7 类的方法中使用函数指针  
```cpp
//definision
void List::visit(void (*pf)(double &num))
{
    Node *flag;
    int i = 1;
    flag = head;
    while (flag != nullptr) {
        std::cout << "Operation #" << i++ << ": ";
        pf(flag->data);
        flag = flag->next;
        std::cout << std::endl;
    }
}

void half(double &num)
{
    std::cout << num << " half is: " << (num /= 2.0);
}

//using
List lin1;
lin1.visit(half);// 函数指针做参数 不用带函数的参数

```