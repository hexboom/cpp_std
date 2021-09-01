#ifndef MOVE_H_
#define MOVE_H_

class Move {
   private:
    double x, y;

   public:
    Move(double x = 0, double y = 0);
    void Show() const;
    Move Add(const Move& m) const;
    void Reset(double x = 0, double y = 0);
    Move operator+(const Move& m) const; 
};

#endif