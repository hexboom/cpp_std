#include "bankacct.h"

#include <iostream>

Bankacct::Bankacct(const std::string &str, long num, double bal)
{
    name = str;
    acct_num = num;
    balance = bal;
}

void Bankacct::viewacct() const
{
    std::cout << "Bank Account Details:\n"
              << "Name: " << name << std::endl
              << "Account Number: " << acct_num << std::endl
              << "Banlance: $" << balance << std::endl;
}

bool Bankacct::deposit(double amt)
{
    if (amt < 0) {
        std::cout << "Refuse negative deposit, deposit cancelled.\n";
        return false;
    } else {
        balance += amt;
        return true;
    }
}

double Bankacct::withdraw(double amt)
{
    if (amt < 0) {
        std::cout << "Refuse negative deposit, deposit canceled.\n";
        return false;
    } else if (amt <= balance) {
        balance -= amt;
        return true;
    } else {
        std::cout << "Withdrawal amount lager exceeds your balance, "
                  << "withdraw canceled.\n";
        return false;
    }
}