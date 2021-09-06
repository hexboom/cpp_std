#ifndef VECTOR1_H_
#define VECTOR1_H_

#include <cmath>
#include <iostream>

#ifndef ANG_TO_RAG_
#define ANG_TO_RAG_
const double ang_to_rag = atan(1.0) / 45.0;
#endif

class Vector1 {
   public:
    enum Mode { RECT,
                POL };

   private:
    double x, y;
    // double mag, ang;
    Mode mode;

    void set_x(double mag, double ang);
    void set_y(double mag, double ang);

   public:
    Vector1(double n1 = 0, double n2 = 0, Mode form = RECT);
    ~Vector1();
    void Reset(double n1 = 0, double n2 = 0, Mode form = RECT);
    double xVal() const { return x; }
    double yVal() const { return y; }
    double magVal() const { return sqrt(x * x + y * y); }
    double angVal() const { return atan2(y, x); }
    void RECT_mode();
    void POL_mode();

    Vector1 operator+(const Vector1 &b) const;
    Vector1 operator-(const Vector1 &b) const;
    Vector1 operator-() const;
    Vector1 operator*(double &z) const;

    friend Vector1 operator*(double &z, const Vector1 &b);
    friend std::ostream &operator<<(std::ostream &os, const Vector1 &b);
};
#endif