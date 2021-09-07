#include "plorg.h"

#include <cstring>
#include <iostream>
Plorg::Plorg(const char* n, int c)
{
    if (strlen(n) <= LEN - 1)
        strcpy(name, n);
    else {
        strncpy(name, n, LEN - 1);
        name[LEN - 1] = '\0';
    }
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