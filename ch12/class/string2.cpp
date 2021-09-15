#include "string2.h"

#include <cctype>
#include <cstring>
#include <iostream>

int String2::StNum()
{
    return num_strings;
}
int String2::num_strings = 0;

String2::String2()
{
    str = new char[1];
    str[0] = '\0';
    len = 0;
    ++num_strings;
}
String2::String2(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    ++num_strings;
}
String2::String2(const String2 &st)
{
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    ++num_strings;
}
String2::~String2()
{
    // std::cout << '\"' << str << '\"' << " has been deleted, "
    //           << --num_strings << " left.\n";
    delete[] str;
    --num_strings;
}

void String2::StrLow()
{
    for (int i = 0; i < len && str[i] != '\0'; ++i)
        str[i] = tolower(str[i]);
}
void String2::StrUp()
{
    for (int i = 0; i < len && str[i] != '\0'; ++i)
        str[i] = toupper(str[i]);
}
int String2::CharFreq(const char ch)
{
    int num = 0;
    for (int i = 0; i < len && str[i] != '\0'; ++i)
        if (str[i] == ch) ++num;
    return num;
}

String2 &String2::operator=(const char *s)
{
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}
String2 &String2::operator=(const String2 &st)
{
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}
char &String2::operator[](int i)
{
    return str[i];
}
const char &String2::operator[](int i) const
{
    return str[i];
}

String2 operator+(const String2 &st1, const String2 &st2)
{
    char str[st1.length() + st2.length() + 2] = {};
    strcat(str, st1.str);
    strcat(str, st2.str);
    return String2(str);
}
bool operator<(const String2 &st1, const String2 &st2)
{
    return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String2 &st1, const String2 &st2)
{
    return (strcmp(st1.str, st2.str) > 0);
}
bool operator==(const String2 &st1, const String2 &st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}
std::ostream &operator<<(std::ostream &os, const String2 &st)
{
    os << st.str;
    return os;
}
std::istream &operator>>(std::istream &is, String2 &st)
{
    char temp[String2::CINLIM];
    is.get(temp, String2::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}