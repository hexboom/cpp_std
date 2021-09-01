#include "golf.h"

#include <cstring>
#include <iostream>
Golf::Golf(const char* name, int hc)
{
    if (strlen(name) <= Len)
        strcpy(fullname, name);
    else {
        std::cout << "name length overflows.\n";
        strncpy(fullname, name, Len);
        fullname[Len - 1] = '\0';
    }
    handicap = hc;
}
Golf::Golf()
{
    char name[Len] = "";
    int hand = 0;
    std::cout << "Enter the name: ";
    std::cin.getline(name, Len);
    std::cout << "Enter the handicap: ";
    std::cin >> hand;
    *this = Golf(name, hand);

    // std::cout << "Enter the name: ";
    // std::cin.getline(fullname, Len);
    // std::cout << "Enter the handicap: ";
    // std::cin >> handicap;
}
void Golf::show() const
{
    std::cout << "Fullname: " << fullname << "\t"
              << "Handicap: " << handicap << std::endl;
}