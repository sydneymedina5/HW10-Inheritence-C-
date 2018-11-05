#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
    public:
        Account();
        Account(std::string, double);
        virtual ~Account();
        bool withdraw(double);
        bool deposit(double);
        int getAccountNumber();
        double getBalance();
        static int getNumberAccounts();
        virtual void print();
        std::string getOwnerName();

    protected:
        double balance;
        static int numberAccounts;

    private:
        int accountNumber;
        std::string ownerName;
}; // end Account.h
#endif // ACCOUNT_H
