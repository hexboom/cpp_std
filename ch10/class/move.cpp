#include "move.h"

#include <iostream>
Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::Show() const
{
    std::cout << "x = " << x
              << "\ty = " << y << std::endl;
}
Move Move::Add(const Move& m) const
{
    return Move(x + m.x, y + m.y);
    // return Move(this->x + m.x, this->y + m.y);
}
void Move::Reset(double a, double b)
{
    x = a;
    y = b;
}
Move Move::operator+(const Move& m) const
{
    return Move(this->x + m.x, this->y + m.y);
}