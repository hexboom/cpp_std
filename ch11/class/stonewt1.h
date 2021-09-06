#ifndef STONEWT1_H_
#define STONEWT1_H_

#include <iostream>
class Stonewt1 {
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
    Stonewt1(double lbs, Mode form = LBS);           // constructor for double pounds
    Stonewt1(int stn, double lbs, Mode form = STN);  // constructor for stone, lbs
    Stonewt1();                                      // default constructor
    ~Stonewt1();
    bool SetMode(Mode form = STN);

    Stonewt1 operator+(const Stonewt1& st) const;
    Stonewt1 operator-(const Stonewt1& st) const;
    Stonewt1 operator*(double mult) const;

    friend Stonewt1 operator*(double mult, const Stonewt1& st)
    {
        return st * mult;
    }
    friend std::ostream& operator<<(std::ostream& os, const Stonewt1& st);
};
#endif