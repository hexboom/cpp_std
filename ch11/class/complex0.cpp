#include "complex0.h"
// void Complex0::Show() const
// {
//     std::cout << "(" << re << ", " << im << "i) ";
// }
Complex0 Complex0::operator+(Complex0 &b) const
{
    return Complex0(this->re + b.re, this->im + b.im);
}
Complex0 Complex0::operator-(Complex0 &b) const
{
    return Complex0(this->re - b.re, this->im - b.im);
}
Complex0 Complex0::operator*(Complex0 &b) const
{
    return Complex0(this->re * b.re - this->im * b.im,
                    this->re * b.im + this->im * b.re);
}
Complex0 Complex0::operator*(double z) const
{
    return Complex0(z * this->re, z * this->im);
}
Complex0 Complex0::operator~() const
{
    return Complex0(this->re, -this->im);
}

Complex0 operator*(double z, Complex0 &b)
{
    return b * z;
}
std::istream &operator>>(std::istream &is, Complex0 &a)
{
    std::cout << "Real part: ";
    if (!(is >> a.re)) {
        std::cout << "Bad enterance. ";
    }
    is.get();
    return is;
    std::cout << "Imaginary Part: ";
    if (!(is >> a.im)) {
        std::cout << "Bad enterance. ";
    }
    is.get();
    return is;
}
std::ostream &operator<<(std::ostream &os, Complex0 &a)
{
    return os << "(" << a.re << ", " << a.im << "i) ";
}