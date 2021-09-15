#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <new>

#include "stringbad.h"
void test1()
{
    char s[5] = "Abcd";
    std::cout << std::strlen(s);
    char ss[7];
    strncpy(ss, s, strlen(s) + 1);
    std::cout << ss << std::endl
              << std::strlen(ss);
}

void test2()
{
    std::cout << "t1:\n";
    char *pt1 = new char[10];
    strcpy(pt1, "Hello");
    printf("0x%hp\n", pt1);
    std::cout << (void *)pt1 << ':' << pt1 << std::endl;
    char *pt2 = pt1;
    std::cout << (void *)pt2 << ':' << pt2 << std::endl;
    delete[] pt2;
    delete[] pt2;
    // free(pt2);
    std::cout << (void *)pt1 << ':' << pt1 << std::endl;
    std::cout << (void *)pt2 << ':' << pt2 << std::endl;
    // char *pt3 = nullptr;
    // printf("0x%hp\n", pt3);

    std::cout << "t2:\n";
    char *pt3 = (char *)malloc(10);
    strcpy(pt3, "Hello");
    printf("0x%hp\n", pt3);
    std::cout << (void *)pt3 << ':' << pt3 << std::endl;
    char *pt4 = pt3;
    std::cout << (void *)pt4 << ':' << pt4 << std::endl;
    free(pt4);
    std::cout << (void *)pt3 << ':' << pt3 << std::endl;
    std::cout << (void *)pt4 << ':' << pt4 << std::endl;
}

void callme1(StringBad &rsb)
{
    std::cout << "String passed by reference:\n";
    std::cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    std::cout << "String passed by value:\n";
    std::cout << "    \"" << sb << "\"\n";
}

int vegnews()
{
    using std::endl;
    {
        std::cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        std::cout << "headline1: " << headline1 << endl;
        std::cout << "headline2: " << headline2 << endl;
        std::cout << "sports: " << sports << endl;
        callme1(headline1);
        std::cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        std::cout << "headline2: " << headline2 << endl;
        std::cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        std::cout << "sailor: " << sailor << endl;
        std::cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        std::cout << "knot: " << knot << endl;
        std::cout << "Exiting the block.\n";
    }
    std::cout << "End of main()\n";
    // std::cin.get();
    return 0;
}

int *poit1(int *pt)
{
    return pt;
}
int *const poit2(int *const pt)
{
    return pt;
}
int *poit3(int &pt)
{
    return &pt;
}

int &reft1(int &pt)
{
    return pt;
}
int &reft2(int *pt)
{
    return *pt;
}
int &reft3(int *const pt)
{
    return *pt;
}

void test4()
{
    int a = 100;
    int aa = 200;
    int &b = a;
    int *const c = &a;
    printf("a 0x%hp : %d\n", &a, a);
    printf("b 0x%hp : %d\n", &b, b);
    printf("*c 0x%hp : %d  &c : 0x%x\n", c, *c, &c);

    b = aa;

    printf("a 0x%hp : %d\n", &b, b);
    printf("aa 0x%hp : %d\n", &aa, aa);
    printf("b 0x%hp : %d\n", &b, b);
    printf("*c 0x%hp : %d  &c : 0x%x\n", c, *c, &c);

    *c = 100;
    //c = &aa;

    int &d = reft1(a);
    printf("d 0x%hp : %d\n", &d, d);
    d = reft1(aa);
    printf("d 0x%hp : %d\n", &d, d);

    int &e = reft3(&b);
    printf("e 0x%hp : %d\n", &e, e);

    int *f = poit2(&a);
    printf("*f 0x%hp : %d  &f : 0x%x\n", f, *f, &f);
    int *g = poit3(a);
    printf("*g 0x%hp : %d  &g : 0x%x\n", g, *g, &g);

    int *h = &reft1(a);
    printf("*h 0x%hp : %d  &h : 0x%x\n", h, *h, &h);
    int &i = *poit1(&a);
    printf("i 0x%hp : %d\n", &i, i);

    int j;
    j = reft1(a);
    printf("a 0x%hp : %d\n", &a, a);
    printf("j 0x%hp : %d\n", &j, j);
    a = 300;
    printf("a 0x%hp : %d\n", &a, a);
    printf("j 0x%hp : %d\n", &j, j);
}

const int BUF = 512;

class JustTesting {
   private:
    std::string words;
    int number;

   public:
    JustTesting(const std::string &s = "Just Testing", int n = 0)
    {
        words = s;
        number = n;
        std::cout << words << " constructed\n";
    }
    ~JustTesting() { std::cout << words << " destroyed\n"; }
    void Show() const { std::cout << words << ", " << number << std::endl; }
};

void test5()
{
    using namespace std;
    char *buffer = new char[BUF];  // get a block of memory

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;      // place object in buffer
    pc2 = new JustTesting("Heap1", 20);  // place object on heap

    cout << "Memory block addresses:\n"
         << "buffer: "
         << (void *)buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    // fix placement new location
    pc3 = new (buffer + sizeof(JustTesting))
        JustTesting("Better Idea", 6);
    // pc3 = new (buffer) JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    cout << pc1 << ": ";
    pc1->Show();

    delete pc2;           // free Heap1
    delete pc4;           // free Heap2
                          // explicitly destroy placement new objects
    pc3->~JustTesting();  // destroy object pointed to by pc3
    pc1->~JustTesting();  // destroy object pointed to by pc1
    delete[] buffer;      // free buffer
    // std::cin.get();
}

void test6()
{
    std::cout << "\nnew\n";
    // int *pt = (int *)0x6c1640;
    // printf("%d\n", *pt);
    // std::cout << *pt;
    std::cout << "\ndone.\n";
}