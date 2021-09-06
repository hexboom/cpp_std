#ifndef STONEWT2_H_
#define STONEWT2_H_

#include <iostream>
class Stonewt2 {
   public:
    enum Mode { STN,
                LBS };

   private:
    enum { Lbs_per_stn = 14 };  // pounds per stone
    int stone;                  // whole stones
    double pds_left;            // fractional pounds
    double pounds;              // entire weight in pounds
    Mode mode;

   public:
    Stonewt2(double lbs, Mode form = LBS);           // constructor for double pounds
    Stonewt2(int stn, double lbs, Mode form = STN);  // constructor for stone, lbs
    Stonewt2();                                      // default constructor
    ~Stonewt2();
    bool SetMode(Mode form = STN);

    Stonewt2 operator+(const Stonewt2& st) const;
    Stonewt2 operator-(const Stonewt2& st) const;
    Stonewt2 operator*(double mult) const;

    bool operator<(const Stonewt2& st) const;
    bool operator>(const Stonewt2& st) const;
    bool operator<=(const Stonewt2& st) const;
    bool operator>=(const Stonewt2& st) const;
    bool operator==(const Stonewt2& st) const;
    bool operator!=(const Stonewt2& st) const;

    friend Stonewt2 operator*(double mult, const Stonewt2& st)
    {
        return st * mult;
    }
    friend std::ostream& operator<<(std::ostream& os, const Stonewt2& st);
};
#endif