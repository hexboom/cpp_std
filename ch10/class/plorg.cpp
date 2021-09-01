#include "plorg.h"

#include <cstring>
#include <iostream>
Plorg::Plorg(const char* n, int c)
{
    if (strlen(n) <= LEN)
        strcpy(name, n);
    else
        strncpy(name, n, LEN);
    CI = c;
}
void Plorg::SetCI(int c)
{
    CI = c;
}
void Plorg::Show()
{
    std::cout << name << ": " << CI << std::endl;
}