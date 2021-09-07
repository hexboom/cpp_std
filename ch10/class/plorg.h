#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
   private:
    const static int LEN = 20;
    char name[LEN];
    int CI;

   public:
    Plorg(const char* n = "Plorga", int c = 50);
    void SetCI(int c = 50);
    void Show();
};
#endif