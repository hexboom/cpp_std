#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "complex0.h"
#include "mytime.h"
#include "stonewt1.h"
#include "stonewt2.h"
#include "vector0.h"
#include "vector1.h"

void ex1101()
{
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    std::ofstream fout;
    std::cout << "enter distance : ";
    while (!(std::cin >> target)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad entrance ,enter again.\n";
    }

    std::cout << "enter step length: ";
    while (!(std::cin >> dstep)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad ste length ,enter again.\n";
    }

    fout.open("ex1101out.txt");
    fout << "Target Distance: " << target
         << ", Step Size: " << dstep << "\n\n";

    while (result.magVal() < target) {
        fout << steps << ": (x,y) = " << result << std::endl;
        direction = rand() % 360;
        step.Reset(dstep, direction, Vector::POL);
        result = result + step;
        ++steps;
    }
    fout << "\nFinally position: (x,y) = " << result;
    result.POL_mode();
    fout << "\nOr: (mag,ang) = " << result;
    fout << "\nTotal steps: " << steps;
    fout << "\nAverage distance per step: " << result.magVal() / steps;

    std::cout << "Done!\n";
}

void ex1102()
{
    srand(time(0));
    double direction;
    Vector1 step;
    Vector1 result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    std::ofstream fout;
    std::cout << "enter distance : ";
    while (!(std::cin >> target)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad entrance ,enter again.\n";
    }

    std::cout << "enter step length: ";
    while (!(std::cin >> dstep)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad ste length ,enter again.\n";
    }

    fout.open("ex1102out.txt");
    fout << "Target Distance: " << target
         << ", Step Size: " << dstep << "\n\n";

    while (result.magVal() < target) {
        fout << steps << ": (x,y) = " << result << std::endl;
        direction = rand() % 360;
        step.Reset(dstep, direction, Vector1::POL);
        result = result + step;
        ++steps;
    }
    fout << "\nFinally position: (x,y) = " << result;
    result.POL_mode();
    fout << "\nOr: (mag,ang) = " << result;
    fout << "\nTotal steps: " << steps;
    fout << "\nAverage distance per step: " << result.magVal() / steps;

    std::cout << "Done!\n";
}

void ex1103()
{
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    unsigned long maxSteps = 0;
    unsigned long minSteps = -1;
    unsigned long aveSteps = 0;
    unsigned int N = 0;

    std::cout << "Enter test number: ";
    while (!(std::cin >> N)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad number, enter again.\n";
    }
    std::cout << "Enter distance: ";
    while (!(std::cin >> target)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad entrance, enter again.\n";
    }
    std::cout << "Enter step length: ";
    while (!(std::cin >> dstep)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Bad ste length, enter again.\n";
    }

    for (unsigned int i = 0; i < N; ++i) {
        while (result.magVal() < target) {
            direction = rand() % 360;
            step.Reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
        }
        std::cout << "#" << i << ": " << steps << std::endl;
        maxSteps = (steps > maxSteps) ? steps : maxSteps;
        minSteps = (steps < minSteps) ? steps : minSteps;
        aveSteps += steps;
        steps = 0;
        result.Reset(0.0, 0.0);
    }
    aveSteps /= N;
    std::cout << "\nmaximum steps = " << maxSteps;
    std::cout << "\nminimum steps = " << minSteps;
    std::cout << "\naverage steps = " << aveSteps;
    std::cout << "\nDone!\n";
}

void ex1104()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
}

void ex1105()
{
    using std::cout;
    using std::endl;

    Stonewt1 s1;
    Stonewt1 s2 = Stonewt1(2.6);
    Stonewt1 s3 = Stonewt1(3, 2.5, Stonewt1::STN);

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    s3.SetMode(Stonewt1::STN);
    cout << "s3 STN mode, s3 = " << s3 << endl;
    cout << "s3 - s2 = " << s3 - s2 << endl;
    cout << "s2 + s1 = " << s2 + s1 << endl;
    cout << "3*s3 = " << 3 * s3 << endl;
    cout << "s3*2 = " << s3 * 2 << endl;
}

void ex1106()
{
    Stonewt2 st[6] = {
        Stonewt2(4.2),
        Stonewt2(11.9),
        Stonewt2(18.2)};
    double p;
    for (int i = 3; i < 6; ++i) {
        std::cout << "#" << i << ": ";
        while (!(std::cin >> p)) {
            std::cin.clear();
            std::cin.sync();
            std::cout << "Bad ste length, enter again.\n";
        }
        st[i] = Stonewt2(p);
    }
    Stonewt2 st11(11, 0);
    Stonewt2 maxSt = st[0];
    Stonewt2 minSt = st[0];
    int lt11st = 0;
    for (auto& stp : st) {
        maxSt = (stp > maxSt) ? stp : maxSt;
        minSt = (stp < minSt) ? stp : minSt;
        lt11st += int(stp >= st11);
    }
    std::cout << "max Stone: " << maxSt << '\n'
              << "min Stone: " << minSt << '\n'
              << "lager than 11 stones: " << lt11st << '\n';
}

void ex1107()
{
    Complex0 a(3.1, 8.9), b(-1.2, 1.0);
    double z = 10.4;
    std::ofstream fout;
    fout.open("out.txt");
    // a.Show();
    Complex0 c = a + b;
    std::cout << c << std::endl;
    fout << c << std::endl;
    c = a * b;
    std::cout << c << std::endl;
    fout << c << std::endl;
    c = z * a;
    std::cout << "The c is: " << c << std::endl;
    fout << "The c is: " << c << std::endl;
    std::cin >> c;
    std::cout << "The c is: " << c << std::endl;
    fout << "The c is: " << c << std::endl;
}
