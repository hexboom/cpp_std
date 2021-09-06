#include "Vector1.h"

void Vector1::set_x(double mag, double ang)
{
    x = mag * cos(ang);
}
void Vector1::set_y(double mag, double ang)
{
    y = mag * sin(ang);
}

Vector1::Vector1(double n1, double n2, Mode form)
{
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
    } else if (mode == POL) {
        n2 = n2 * ang_to_rag;
        set_x(n1, n2);
        set_y(n1, n2);
    } else {
        std::cout << "Wrong Mode chosed, use defualt setting.\n";
        x = y = 0;
    }
}
Vector1::~Vector1()
{
}

void Vector1::Reset(double n1, double n2, Mode form)
{
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
    } else if (mode == POL) {
        n2 = n2 * ang_to_rag;
        set_x(n1, n2);
        set_y(n1, n2);
    } else {
        std::cout << "Wrong Mode chosed, use defualt setting.\n";
        x = y = 0;
    }
}
void Vector1::RECT_mode()
{
    mode = RECT;
}
void Vector1::POL_mode()
{
    mode = POL;
}

Vector1 Vector1::operator+(const Vector1 &b) const
{
    return Vector1(this->x + b.x, this->y + b.y);
}
Vector1 Vector1::operator-(const Vector1 &b) const
{
    return Vector1(this->x - b.x, this->y - b.y);
}
Vector1 Vector1::operator-() const
{
    return Vector1(-this->x, -this->y);
}
Vector1 Vector1::operator*(double &z) const
{
    return Vector1(z * this->x, z * this->y);
}

Vector1 operator*(double &z, const Vector1 &b)
{
    return b * z;
}
std::ostream &operator<<(std::ostream &os, const Vector1 &b)
{
    if (b.mode == Vector1::RECT)
        os << '(' << b.x << ',' << b.y << ')';
    else if (b.mode == Vector1::POL)
        os << '(' << b.magVal()
           << ',' << b.angVal() / ang_to_rag << "°)";
    else
        os << "Mode is invalid.\n";
    return os;
}