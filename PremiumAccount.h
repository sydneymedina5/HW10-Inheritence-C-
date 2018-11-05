#ifndef PREMIUMACCOUNT_H
#define PREMIUMACCOUNT_H
#include <iomanip>

class PremiumAccount: public Account
{
    public:
        /*is the constructor which increments numberPremiumAccounts and
        passes the arguments to the Account constructor*/
        PremiumAccount(std::string name, double amount):Account(name, amount)
        {
            numberPremiumAccounts++;
        } // end PremiumAccount(std::string name, double amount):Account(name, amount)

        /*Deconstructor*/
        virtual ~PremiumAccount()
        {

        } // end ~PremiumAccount()

        /*A static member function that returns numberPremiumAccounts.*/
        static int getNumberPremiumAccounts()
        {
            return numberPremiumAccounts;
        } // end getNumberPremiumAccounts()

        /*function to withdraw a specified amount from the account.The function should first
        check if the existing balance is greater or equal to the withdrawal amount + MIN_BALANCE.
        If so, withdrawal is processed. Otherwise the withdrawal is not made.
        If the withdrawal is made, the withdrawal amount is deducted from balance*/
        bool withdraw(double amount)
        {
            double with;
            with = getBalance() - amount;

            if(with < 1000)
                return false;

            balance = getBalance() - amount;
            return true;
        } // end withdraw(double amount)

        /*:A static member function that returns MIN_BALANCE*/
        static double getMinBalance()
        {
            return MIN_BALANCE;
        } // end getMinBalance()

        /* overrides the print() of Account. This function prints the string “Premium
        account” then prints accountNumber, ownerName, balance. To print the
        accountNumber, ownerName, balance, call the print function of Account with
        this statement: this->Account::print();*/
        void print() override
        {
            std::cout << "Premium account, Number:" << std::setw(8) << std::right << getAccountNumber();
            std::cout << ", Name:" << std::setw(10) << getOwnerName() << ", Balance: $";
            std::cout << std::setprecision(2) << std::fixed << getBalance();
            std::cout << std::endl;
        } // end print() override

    protected:

    private:
        static int numberPremiumAccounts;
        static double MIN_BALANCE;
}; // end PremiumAccount.h

int PremiumAccount::numberPremiumAccounts = 0;
double PremiumAccount::MIN_BALANCE = 1000;

#endif // PREMIUMACCOUNT_H
