// stonewt.cpp -- Stonewt methods
#include "stonewt1.h"

#include <iostream>
using std::cout;
// construct Stonewt object from double value
Stonewt1::Stonewt1(double lbs, Mode form)
{
    stone = int(lbs) / Lbs_per_stn;  // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = form;
}

// construct Stonewt object from stone, double values
Stonewt1::Stonewt1(int stn, double lbs, Mode form)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}

Stonewt1::Stonewt1()  // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = STN;
}

Stonewt1::~Stonewt1()  // destructor
{
}

bool Stonewt1::SetMode(Mode form)
{
    if (form == STN || form == LBS) {
        mode = form;
        return true;
    }
    std::cout << "Invalid format.\n";
    return false;
}

Stonewt1 Stonewt1::operator+(const Stonewt1& st) const
{
    return Stonewt1(this->pounds + st.pounds);
}
Stonewt1 Stonewt1::operator-(const Stonewt1& st) const
{
    return Stonewt1(this->pounds - st.pounds);
}
Stonewt1 Stonewt1::operator*(double mult) const
{
    return Stonewt1(this->pounds * mult);
}

std::ostream &operator<<(std::ostream &os, const Stonewt1 &st)
{
    switch (st.mode) {
        case Stonewt1::STN:
            os << st.stone << " stone, " << st.pds_left << " pounds\n";
            break;
        case Stonewt1::LBS:
            os << st.pounds << " pounds\n";
            break;
        default:
            os << "Invalid format.\n";
            break;
    }
    
    return os;
}