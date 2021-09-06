#include "vector0.h"

void Vector::set_x()
{
    x = mag * cos(ang);
}
void Vector::set_y()
{
    y = mag * sin(ang);
}
void Vector::set_ang()
{
    ang = atan2(y, x);
}
void Vector::set_mag()
{
    mag = sqrt(x * x + y * y);
}

Vector::Vector(double n1, double n2, Mode form)
{
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    } else if (mode == POL) {
        mag = n1;
        ang = n2 * ang_to_rag;
        set_x();
        set_y();
    } else {
        std::cout << "Wrong Mode chosed, use defualt setting.\n";
        x = y = ang = mag = 0;
    }
}
Vector::~Vector()
{
}

void Vector::Reset(double n1, double n2, Mode form)
{
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    } else if (mode == POL) {
        mag = n1;
        ang = n2;
        set_x();
        set_y();
    } else {
        std::cout << "Wrong Mode chosed, use defualt setting.\n";
        x = y = ang = mag = 0;
    }
}
void Vector::RECT_mode()
{
    mode = RECT;
}
void Vector::POL_mode()
{
    mode = POL;
}

Vector Vector::operator+(const Vector &b) const
{
    return Vector(this->x + b.x, this->y + b.y);
}
Vector Vector::operator-(const Vector &b) const
{
    return Vector(this->x - b.x, this->y - b.y);
}
Vector Vector::operator-() const
{
    return Vector(-this->x, -this->y);
}
Vector Vector::operator*(double &z) const
{
    return Vector(z * this->x, z * this->y);
}

Vector operator*(double &z, const Vector &b)
{
    return b * z;
}
std::ostream &operator<<(std::ostream &os, const Vector &b)
{
    if (b.mode == Vector::RECT)
        os << '(' << b.x << ',' << b.y << ')';
    else if (b.mode == Vector::POL)
        os << '(' << b.mag << ',' << b.ang / ang_to_rag << "°)";
    else
        os << "Mode is invalid.\n";
    return os;
}