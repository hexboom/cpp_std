#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>
class Complex0 {
   private:
    double re, im;

   public:
    Complex0(double x = 0, double y = 0)
    {
        re = x;
        im = y;
    }
    // void Show() const;
    Complex0 operator+(Complex0 &b) const;
    Complex0 operator-(Complex0 &b) const;
    Complex0 operator*(Complex0 &b) const;
    Complex0 operator*(double z) const;
    Complex0 operator~() const;

    friend Complex0 operator*(double z, Complex0 &b);
    friend std::istream &operator>>(std::istream &is, Complex0 &a);
    friend std::ostream &operator<<(std::ostream &os, Complex0 &a);
};

#endif