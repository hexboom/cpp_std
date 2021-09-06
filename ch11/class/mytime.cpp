#include "mytime.h"

Time::Time()
{
    hours = 0;
    minutes = 0;
}
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::AddMin(int m)
{
    hours += (m + minutes) / 60;
    minutes = (m + minutes) % 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time& t1, const Time& t2)
{
    return Time(t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60,
                (t1.minutes + t2.minutes) % 60);
}
Time operator-(const Time& t1, const Time& t2)
{
    int total;
    total = (t1.hours * 60 + t1.minutes) - (t2.hours * 60 + t2.minutes);
    return Time(total / 60, total % 60);
}
Time operator*(const Time& t, double m)
{
    long total = t.hours * m * 60 + (t.minutes * m);
    // std::cout << total / 60 << '\t'
    //           << total % 60 << '\n';
    return Time(total / 60, total % 60);
    // return Time(t.hours * m + (t.minutes * m) / 60,
    //             (long(t.hours * m * 60 + t.minutes * m)) % 60);
}
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}