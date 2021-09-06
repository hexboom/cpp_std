#ifndef VECTOR0_H_
#define VECTOR0_H_

#include <cmath>
#include <iostream>

#ifndef ANG_TO_RAG_
#define ANG_TO_RAG_
const double ang_to_rag = atan(1.0) / 45.0;
#endif

class Vector {
   public:
    enum Mode { RECT,
                POL };

   private:
    // static constexpr double pai = 3.1415926;
    // static constexpr double ang_to_rag = pai / 180.0;
    double x, y;
    double mag, ang;
    Mode mode;

    void set_x();
    void set_y();
    void set_mag();
    void set_ang();

   public:
    Vector(double n1 = 0, double n2 = 0, Mode form = RECT);
    ~Vector();
    void Reset(double n1 = 0, double n2 = 0, Mode form = RECT);
    double xVal() const { return x; }
    double yVal() const { return y; }
    double magVal() const { return mag; }
    double angVal() const { return ang / ang_to_rag; }
    void RECT_mode();
    void POL_mode();

    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator-() const;
    Vector operator*(double &z) const;

    friend Vector operator*(double &z, const Vector &b);
    friend std::ostream &operator<<(std::ostream &os, const Vector &b);
};
#endif