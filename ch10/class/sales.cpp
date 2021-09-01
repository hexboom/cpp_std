#include "sales.h"

#include <iostream>
using namespace SALES;
Sales::Sales(const double *ar, int n)
{
    num = n;
    average = 0;
    max = *ar;
    min = *ar;
    for (int i = 0; i < QUARTERS; ++i) {
        if (i < n) {
            sales[i] = ar[i];
            average += ar[i];
            if (ar[i] > max)
                max = ar[i];
            if (ar[i] < min)
                min = ar[i];
        } else
            sales[i] = 0;
    }
    average /= num;
}
Sales::Sales()
{
    int n;
    double ar[QUARTERS];
    std::cout << "Enter the items quality: ";
    while (!(std::cin >> n && n <= 4))
        std::cout << "Error enter, plz enter again: ";
    std::cout << "Enter the sales values:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "#" << i + 1 << ": ";
        std::cin >> ar[i];
    }
    *this = Sales(ar, n);
}
void Sales::Show()
{
    std::cout << "Sales: \n";
    for (int i = 0; i < num; ++i)
        std::cout << "#" << i + 1 << ": "
                  << sales[i] << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
}