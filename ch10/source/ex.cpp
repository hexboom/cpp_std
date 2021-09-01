#include <iostream>
#include <string>

#include "bankacct.h"
#include "golf.h"
#include "list.h"
#include "move.h"
#include "person.h"
#include "plorg.h"
#include "sales.h"
#include "stack.h"
void ex1001()
{
    Bankacct acc1;
    Bankacct acc2("Example Account", 28392, 100.1);
    acc1.viewacct();
    std::cout << std::endl;
    acc2.viewacct();
    std::cout << std::endl;
    acc2.deposit(-1);
    std::cout << std::endl;
    acc2.deposit(22.3);
    acc2.viewacct();
    std::cout << std::endl;
    acc2.withdraw(-1);
    std::cout << std::endl;
    acc2.withdraw(200);
    std::cout << std::endl;
    acc2.withdraw(51.2);
    acc2.viewacct();
    std::cout << std::endl;
}

void ex1002()
{
    Person one;
    Person two("Smythecraft");
    Person three{"Dimwiddy", "Samgfsertqrtqertwertwsdfgqrt"};
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
}

void ex1003()
{
    Golf g1;
    g1.show();
    Golf g2("Amy Olliev", 12);
    g2.show();
}

void ex1004()
{
    using namespace SALES;
    double ar[3] = {9.1, 8.3, 7.4};
    Sales s1(ar, 3);
    s1.Show();
    Sales s2;
    s2.Show();
}

struct customer {
    std::string fullname;
    double payment;
};

void ex1005()
{
    double total = 0.0;
    customer pop;
    Stack<customer> stack1;
    customer customer1 = {"jimmy", 1000};

    Stack<int> stack2;
    stack2.push(11);
    if (stack1.push(customer1)) {
        std::cout << customer1.fullname << " push." << std::endl;
    } else {
        std::cout << "stack1 full." << std::endl;
    }

    customer customer2 = {"hey", 200.0};

    if (stack1.push(customer2)) {
        std::cout << customer2.fullname << " push." << std::endl;
    } else {
        std::cout << "stack1 full." << std::endl;
    }

    if (stack1.pop(pop)) {
        std::cout << pop.fullname << " pop." << std::endl;
        total += pop.payment;
    } else
        std::cout << "stack1 empty." << std::endl;

    customer customer3 = {"kitty", 3000.0};
    if (stack1.push(customer3))
        std::cout << customer3.fullname << " push." << std::endl;
    else
        std::cout << "stack1 full." << std::endl;

    if (stack1.pop(pop)) {
        std::cout << pop.fullname << " pop." << std::endl;
        total += pop.payment;
    } else
        std::cout << "stack1 empty." << std::endl;

    if (stack1.pop(pop)) {
        std::cout << pop.fullname << " pop." << std::endl;
        total += pop.payment;
    } else
        std::cout << "stack1 empty." << std::endl;

    if (stack1.pop(pop)) {
        std::cout << pop.fullname << " pop." << std::endl;
        total += pop.payment;
    } else
        std::cout << "stack1 empty." << std::endl;
    std::streamsize prec = std::cout.precision(3);
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);
    std::cout << "Total paymemt: " << total << std::endl;
    std::cout.precision(prec);
    std::cout.setf(orig, std::ios_base::floatfield);
}

void ex1006()
{
    Move m1;
    m1.Show();
    Move m2 = {2.3, 5.4}, m3{1.2, 10.2};
    m2.Show();
    m3.Show();
    m1 = m2 + m3;
    m1.Show();
    m1 = m1.Add(m2);
    m1.Show();
}

void ex1007()
{
    Plorg p1;
    p1.Show();
    Plorg p2("Akol", 10);
    p2.Show();
    p2.SetCI(30);
    p2.Show();
}

void ex1008()
{
    List<double> lin1;
    std::cout << "=====INSERT=====\n";
    lin1.Insert(3.0);
    lin1.Insert(4);
    lin1.Insert(1);
    lin1.Print();
    lin1.Insert(11, 2);
    lin1.Print();
    lin1.Insert(13, 10);
    lin1.Print();
    lin1.Insert(15, 3);
    lin1.Print();
    lin1.Insert(20, 7);
    lin1.Print();
    std::cout << "=====VISIT=====\n";
    lin1.visit(half<double>);
}