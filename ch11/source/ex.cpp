#include <iostream>

#include "complex0.h"

void ex1107()
{
    Complex0 a(3.1, 8.9), b(-1.2, 1.0);
    double z = 10.4;
    // a.Show();
    Complex0 c = a + b;
    std::cout << c << std::endl;
    c = a * b;
    std::cout << c << std::endl;
    c = z * a;
    std::cout << "The c is: " << c << std::endl;
    std::cin >> c;
    std::cout << "The c is: " << c << std::endl;
}