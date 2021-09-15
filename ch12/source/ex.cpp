#include <ctime>
#include <iostream>

#include "cow.h"
#include "queue.h"
#include "stack.h"
#include "stock.h"
#include "string2.h"

void ex1201()
{
    {
        Cow c1;
        c1.ShowCow();
        Cow c2("Cow2", "eating", 20);
        c2.ShowCow();
        Cow c3(c2);
        c3.ShowCow();
        c1 = c2;
        c1.ShowCow();
    }
    std::cout << "Done!\n";
}

void ex1202()
{
    String2 st1;
    String2 st2("Halo wee. ");
    String2 st3 = "Pew loo. ";
    String2 st4(st2);
    std::cout << st1 << ": " << st1.length() << std::endl
              << st2 << ": " << st2.length() << std::endl
              << st3 << ": " << st3.length() << std::endl
              << st4 << ": " << st4.length() << std::endl;
    st4 = st3;
    std::cout << st3 << ": " << st3.length() << std::endl
              << st4 << ": " << st4.length() << std::endl;
    std::cout << (st4 > st3) << '\t'
              << (st4 < st3) << '\t'
              << (st4 == st3) << std::endl;
    st4[4] = 'P';
    std::cout << st4 << ": " << st4.length() << std::endl;
    std::cout << (st4 > st3) << '\t'
              << (st4 < st3) << '\t'
              << (st4 == st3) << std::endl;
    st4[6] = st2[0];
    std::cout << st4 << ": " << st4.length() << std::endl;
    st4 = "HappY PepPer. ";

    std::cout << st4 << ": " << st4.length() << std::endl;
    std::cout << "p: " << st4.CharFreq('p') << '\t'
              << "P: " << st4.CharFreq('P') << std::endl;

    st4.StrLow();
    std::cout << st4 << ": " << st4.length() << std::endl;
    st4.StrUp();
    std::cout << st4 << ": " << st4.length() << std::endl;

    std::cin >> st4;
    std::cout << st4 << ": " << st4.length() << std::endl;

    st4 = st2 + st4;
    std::cout << st4 << ": " << st4.length() << std::endl;

    st4 = "Alpd apdf " + st4;
    std::cout << st4 << ": " << st4.length() << std::endl;
    st4 = st4 + "Ploa dd";
    std::cout << st4 << ": " << st4.length() << std::endl;
    std::cout << st4.StNum() << '\t'
              << String2::StNum() << std::endl;
}

void ex1202_2()
{
    using namespace std;
    String2 s1("and i am a C++ student.");
    String2 s2 = "Please enter your name: ";
    String2 s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.StrUp();
    cout << "The sting\n"
         << s2 << "\ncontains " << s2.CharFreq('A')
         << " 'A' characters in it.\n";
    s1 = "red";
    String2 rgb[3] = {String2(s1), String2("green"), String2("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String2 ans;
    bool success = false;
    while (cin >> ans) {
        ans.StrLow();
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success) {
            break;
        } else {
            cout << "Try again!\n";
        }
    }
    cout << "Bye!\n";
}

void ex1203()
{
    const int STKS = 4;
    // create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)};

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        std::cout << stocks[st];
    // set pointer to first element
    const Stock* top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    // now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n"
              << *top;
}

#define QUEUE_H_
void ex1204()
{
    Stack st1;
    Stack st2(5);
    for (int i = 0; i < 10; ++i) {
        if (!st2.isfull())
            st2.push(i);
        else
            break;
    }
    st1 = st2;
    int num;
    for (int i = 0; i < 10; ++i) {
        if (!st1.isempty()) {
            st1.pop(num);
            std::cout << num << std::endl;
        } else
            break;
    }
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
const int MIN_PER_HR = 60;
void ex1205()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));  //  random initializing of rand()

    Queue line;

    int hours = 100;  //  hours of simulation
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;  // # of cycles

    double perhour = 1;   //  average # of arrival per hour
    double min_per_cust;  //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    ItemCus temp;        //  new customer data
    long turnaways = 0;  //  turned away by full queue
    long customers = 0;  //  joined the queue
    long served = 0;     //  served during the simulation
    long sum_line = 0;   //  cumulative line length
    int wait_time = 0;   //  time until autoteller is free
    long line_wait = 0;  //  cumulative time in line
    double ave_wait_time = 0;

    while (ave_wait_time <= 1) {
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line.isfull())
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle);     // cycle = time of arrival
                    line.enqueue(temp);  // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty()) {
                line.dequeue(temp);        // attend next customer
                wait_time = temp.ptime();  // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }
        ave_wait_time = (double)line_wait / served;

        // cout << "Average number of arrival per hour: " << perhour++ << endl
        //      << "                 Average wait time: " << ave_wait_time << " minutes\n";
    }

    // reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl
             << "  customers served: " << served << endl
             << "         turnaways: " << turnaways << endl
             << "Average number of arrival per hour: " << perhour << endl
             << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl
             << " average wait time: " << ave_wait_time << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
}

void ex1206()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));  //  random initializing of rand()

    Queue line1, line2;

    int hours = 100;  //  hours of simulation
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;  // # of cycles

    double perhour = 1;   //  average # of arrival per hour
    double min_per_cust;  //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    ItemCus temp, process1, process2;  //  new customer data
    long turnaways = 0;                //  turned away by full queue
    long customers = 0;                //  joined the queue
    long served = 0;                   //  served during the simulation
    long sum_line1 = 0;                //  cumulative line length
    long sum_line2 = 0;
    int wait_time1 = 0;  //  time until autoteller is free
    int wait_time2 = 0;
    long line_wait = 0;  //  cumulative time in line
    double ave_wait_time = 0;

    while (ave_wait_time <= 1) {
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line1 = 0;
        sum_line2 = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle);  // cycle = time of arrival
                    if (line1.queuecount() < line2.queuecount())
                        line1.enqueue(temp);  // add newcomer to line
                    else
                        line2.enqueue(temp);
                }
            }
            if (wait_time1 <= 0 && !line1.isempty()) {
                line1.dequeue(process1);        // attend next customer
                wait_time1 = process1.ptime();  // for wait_time minutes
                line_wait += cycle - process1.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line1 += line1.queuecount();

            if (wait_time2 <= 0 && !line2.isempty()) {
                line2.dequeue(process2);        // attend next customer
                wait_time2 = process2.ptime();  // for wait_time minutes
                line_wait += cycle - process2.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line2 += line2.queuecount();
        }
        ave_wait_time = (double)line_wait / served;

        // cout << "Average number of arrival per hour: " << perhour++ << endl
        //      << "                 Average wait time: " << ave_wait_time << " minutes\n";
    }

    // reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl
             << "  customers served: " << served << endl
             << "         turnaways: " << turnaways << endl
             << "Average number of arrival per hour: " << perhour << endl
             << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)(sum_line1 + sum_line2) / cyclelimit << endl
             << " average wait time: " << ave_wait_time << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
}
