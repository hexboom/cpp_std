// stonewt.cpp -- Stonewt methods
#include "stonewt2.h"

#include <iostream>
using std::cout;
// construct Stonewt object from double value
Stonewt2::Stonewt2(double lbs, Mode form)
{
    stone = int(lbs) / Lbs_per_stn;  // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = form;
}

// construct Stonewt object from stone, double values
Stonewt2::Stonewt2(int stn, double lbs, Mode form)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}

Stonewt2::Stonewt2()  // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = STN;
}

Stonewt2::~Stonewt2()  // destructor
{
}

bool Stonewt2::SetMode(Mode form)
{
    if (form == STN || form == LBS) {
        mode = form;
        return true;
    }
    std::cout << "Invalid format.\n";
    return false;
}

Stonewt2 Stonewt2::operator+(const Stonewt2& st) const
{
    return Stonewt2(this->pounds + st.pounds);
}
Stonewt2 Stonewt2::operator-(const Stonewt2& st) const
{
    return Stonewt2(this->pounds - st.pounds);
}
Stonewt2 Stonewt2::operator*(double mult) const
{
    return Stonewt2(this->pounds * mult);
}

bool Stonewt2::operator<(const Stonewt2& st) const
{
    return (this->pounds < st.pounds);
}
bool Stonewt2::operator>(const Stonewt2& st) const
{
    return (this->pounds > st.pounds);
}
bool Stonewt2::operator<=(const Stonewt2& st) const
{
    return (this->pounds < +st.pounds);
}
bool Stonewt2::operator>=(const Stonewt2& st) const
{
    return (this->pounds >= st.pounds);
}
bool Stonewt2::operator==(const Stonewt2& st) const
{
    return (this->pounds == st.pounds);
}
bool Stonewt2::operator!=(const Stonewt2& st) const
{
    return (this->pounds != st.pounds);
}

std::ostream&
operator<<(std::ostream& os, const Stonewt2& st)
{
    switch (st.mode) {
        case Stonewt2::STN:
            os << st.stone << " stone, " << st.pds_left << " pounds\n";
            break;
        case Stonewt2::LBS:
            os << st.pounds << " pounds\n";
            break;
        default:
            os << "Invalid format.\n";
            break;
    }

    return os;
}