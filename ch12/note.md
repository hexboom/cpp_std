# 类内内存分配和拷贝构造函数 #

## 1.1 打印指针指向的地址值
用(void*)强制类型转换或printf中%p输出控制。
```cpp
char *pt1 = new char[10];
strcpy(pt1, "Hello");

printf("0x%hp\n", pt1);
std::cout << (void *)pt1 << ':' <<pt1 << std::endl;
```

## 1.2 delete
delete释放空间后指针指的地址还是之前的地址。指向的内存块被释放。

## 1.3 不能用free释放new的动态内存
new和delete的本质是一个函数，malloc和free只是这两个函数中的一句调用语句，所以当你用new申请内存，却用free释放，相当于用整个函数来申请内存并维护了一个逻辑使内存方便使用，但是只用了一个free语句就释放掉内存，使这个逻辑出现错误，因为这是个逻辑错误而不是语法错误，所以编译器不会识别（牛B的可能会警告），运行时如果你的程序指令有严重问题，只好段错误或吐核，碰巧这个问题没有影响到操作系统，也不说明这是一个良好的程序。

## 1.4 静态成员函数
静态成员函数只能访问静态变量，使用静态成员函数既可以用成员访问运算符，也可以用作用域解析运算符。
```cpp
class String2{
   private:
    static int num_strings;
   public:
    static int StNum();
}
std::cout << st4.StNum() << '\t'
          << String2::StNum() << std::endl;
```
如果静态成员的初始化不在.h的声明中，静态函数的实现不能在声明中内联实现。