#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "complex0.h"
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
        result.Reset(0.0,0.0);
    }
    aveSteps /= N;
    std::cout << "\nmaximum steps = " << maxSteps;
    std::cout << "\nminimum steps = " << minSteps;
    std::cout << "\naverage steps = " << aveSteps;
    std::cout << "\nDone!\n";
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
