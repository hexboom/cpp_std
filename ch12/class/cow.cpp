#include "cow.h"

#include <cstring>
#include <iostream>
Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}
Cow::Cow(const char *nm, const char *ho, double wt)
{
    if (strlen(nm) < 20)
        strcpy(name, nm);
    else {
        strncpy(name, nm, 19);
        name[19] = '\0';
    }

    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow()
{
    delete[] hobby;
    std::cout << name << " deleted.\n";
}

void Cow::ShowCow() const
{
    std::cout << "Name: " << name
              << "\nHobby: " << hobby
              << "\nWeight: " << weight << std::endl;
}
Cow &Cow::operator=(const Cow &c)
{
    strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}