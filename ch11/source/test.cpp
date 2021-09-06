#include <iostream>
#include "ex.h"
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
    // P(int ain , const std::string &bin)
    {
        a = ain;
        b = bin;
        mode = form;
    }
    void PrintP() const
    {
        std::cout << "a = " << a << '\t'
                  << "b = " << b << '\t'
                  << "Mode = " << mode << std::endl;
    }
    void PPP()
    {
        PrintP();
    }
    ~P()
    {
        std::cout << "delete " << b << std::endl;
    }
};

void test()
{
    P p1(10, "Hell Milly", P::MB);
    P p2;
    p1.PrintP();
    p2.PrintP();
}
