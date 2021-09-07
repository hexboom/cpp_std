#include "person.h"

#include <cstring>
#include <iostream>
#include <string>

Person::Person(const std::string &ln, const char *fn)
{
    lname = ln;
    if (strlen(fn) <= LIMIT - 1)
        strcpy(fname, fn);
    else {
        std::cout << "name length overflows.\n";
        strncpy(fname, fn, LIMIT - 1);
        fname[LIMIT - 1] = '\0';
    }
}
void Person::Show() const
{
    std::cout << fname << ' ' << lname << std::endl;
}
void Person::FormalShow() const
{
    std::cout << lname << ", " << fname << std::endl;
}