#ifndef BANKACCT_H_
#define BANKACCT_H_
#include <string>
class Bankacct {
   private:
    std::string name;
    long acct_num;
    double balance;

   public:
    Bankacct(const std::string& str = "Null Account", long num = -1,
             double bal = 0.0);
    void viewacct() const;
    bool deposit(double amt);
    double withdraw(double amt);
};

#endif
