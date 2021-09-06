# 运算符重载和友元函数 #
1.1 返回值为对象  
这时最好使用构造函数返回一个临时对象。  

1.2 类内枚举  
类内如果是使用常数可以用enum 或者 static const声明。  
如果是要做标识符，则需在public 中声明enum类型。在使用时，需要加上类名作用域。
```cpp
class P {
   public:
    enum Mode { LA,
                MB };

   private:
    int a;
    std::string b;
    Mode mode;

   public:
    P(int ain = -1, const std::string &bin = "NULL", Mode form = LA)
    {···}
};

P p1(10,"hell", P::MB);

```

1.3 类内静态常量  
类内静态常量（static const）只能是整型。如果使用静态浮点变量  
- 不要声明为常量 
- 在类声明外单独定义，可以用**名称空间**限制作用域
- 使用constexpr  
constexpr （const expression）限定在编译时就算出确定值（const的常量语义被分割出来），const只保证在运行的时候变量不变。  


1.4 处理cin中错误类型的缓存流  
```cpp
double target;
while (!(std::cin >> target)) {
    std::cout << std::cin.rdstate() << std::endl;
    std::cin.clear(); //恢复输出状态值
    // std::cout << std::cin.rdstate() << std::endl;
    std::cin.sync();  //清空输入流缓存
    // std::cout << std::cin.rdstate() << std::endl;
    std::cout << "Bad entrance ,enter again.\n";
}
```

1.5 友元函数重载运算符  
使用const运算符可以正确使用 函数的临时返回值做参数。
```cpp
Stonewt Stonewt::operator-(const Stonewt& st) const;

//wrong
std::ostream &operator<<(std::ostream &os, Stonewt &st);
std::cout << "s3 - s2 = " << s3 - s2 << std::endl;    
//right
std::ostream &operator<<(std::ostream &os, const Stonewt &st);
std::cout << "s3 - s2 = " << s3 - s2 << std::endl;    

```