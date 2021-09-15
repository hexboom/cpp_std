#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>

class String2 {
   private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

   public:
    String2();
    String2(const char *s);
    String2(const String2 &st);
    ~String2();

    int length() const { return len; }
    void StrLow();
    void StrUp();
    int CharFreq(const char ch);

    String2 &operator=(const char *s);
    String2 &operator=(const String2 &st);
    char &operator[](int i);
    const char &operator[](int i) const;

    friend String2 operator+(const String2 &st1, const String2 &st2);
    friend bool operator<(const String2 &st1, const String2 &st2);
    friend bool operator>(const String2 &st1, const String2 &st2);
    friend bool operator==(const String2 &st1, const String2 &st2);
    friend std::ostream &operator<<(std::ostream &os, const String2 &st);
    friend std::istream &operator>>(std::istream &is, String2 &st);

    static int StNum();
    // int StNum();
};

#endif