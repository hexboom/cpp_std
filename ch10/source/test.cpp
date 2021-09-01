#include <iostream>

class P {
   private:
    int a;
    std::string b;

   public:
    P(int ain = -1, const std::string &bin = "NULL")
    // P(int ain , const std::string &bin)
    {
        a = ain;
        b = bin;
    }
    void PrintP() const
    {
        std::cout << "a = " << a << '\t' << "b = " << b << std::endl;
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
    {
        P p1;
        p1.PrintP();
        p1.PPP();
        P p2 = P(10.1, "p2 here");
        std::cout << "not use copy \n";
        P p3{11, "p3 here"};
        p3.PrintP();
        const P p4{21, "p4 here"};
        p4.PrintP();


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
    }
    std::cout << "End test";
}