#ifndef REGULARACCOUNT_H
#define REGULARACCOUNT_H
#include <iomanip>

class RegularAccount : public Account
{
    public:
        /* is the constructor which increments numberRegularAccounts
        and passes the arguments to the Account constructor*/
        RegularAccount(std::string name, double amount):Account(name, amount)
        {
            numberRegularAccounts++;
        } // end RegularAccount(std::string name, double amount):Account(name, amount)

        /*Deconstructor*/
        virtual ~RegularAccount()
        {

        } // end ~RegularAccount()

        /* A static member function that returns numberRegularAccounts.*/
        static int getNumberRegularAccounts()
        {
            return numberRegularAccounts;
        } // end getNumberRegularAccounts()

        /*: overrides the print() of Account. This function prints the string “Regular
        account” then prints accountNumber, ownerName, balance. To print the
        accountNumber, ownerName, balance, call the print function of Account with
        this statement: this->Account::print();*/
        void print() override
        {
            std::cout << "Regular account, Number:" << std::setw(8) << std::right << getAccountNumber();
            std::cout << ", Name:" << std::setw(10) << getOwnerName() << ", Balance: $";
            std::cout << std::setprecision(2) << std::fixed << getBalance();
            std::cout << std::endl;
        } // end print()

    protected:

    private:
        static int numberRegularAccounts;
}; // end RegularAccount.h

int RegularAccount::numberRegularAccounts = 0;

#endif // REGULARACCOUNT_H
