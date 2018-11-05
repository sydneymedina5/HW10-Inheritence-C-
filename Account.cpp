#include "Account.h"

int Account::numberAccounts = 0;

/*This is the default constructor*/
Account::Account()
{

} // end Account::Account()

/*the constructor that initializes the account’s
member variables ownerName and balance. balance_ is the amount deposited when the
account is created. accountNumber is set to (numberAccounts+1000) and
numberAccounts is incremented. */
Account::Account(std::string ownerName_, double balance_)
{
    ownerName = ownerName_;
    balance = balance_;
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
} // end Account::Account(std::string ownerName_, double balance_)

/*Deconstructor*/
Account::~Account()
{
    //dtor
} // end Account::~Account()

/*function to withdraw a specified amount from the account. The function
should first check if there is sufficient balance in the account. If the balance is sufficient,
withdrawal is processed. Otherwise the withdrawal is not made. If the withdrawal is made, the
withdrawal amount is deducted from balance.*/
bool Account::withdraw(double amount)
{
    if(amount > getBalance())
        return false;

    balance = getBalance() - amount;
    return true;
} // end Account::withdraw(double amount)

/* function to deposit a specified amount of money to the account. The
function should first check if the deposit amount is positive. If it is positive, deposit is processed.
Otherwise the deposit is not made. If the deposit is made, the amount is added to balance.
 getAccountNumber(): An accessor function that returns the account number.*/
bool Account::deposit(double amount)
{
    if(amount < 0)
        return false;

    balance = getBalance() + amount;
    return true;
} // end Account::deposit(double amount)

//  An accessor function that returns the account number.
int Account::getAccountNumber()
{
    return accountNumber;
} // end Account::getAccountNumber()

// An accessor function that returns the account balance.
double Account::getBalance()
{
    return balance;
} // end Account::getBalance()

// A static member function that returns numberAccounts.
int Account::getNumberAccounts()
{
    return numberAccounts;
} // end Account::getNumberAccounts()

// An accessor function that returns the owners name
std::string Account::getOwnerName()
{
    return ownerName;
} // end Account::getOwnerName()

/* a virtual member function that prints accountNumber, ownerName,
balance.*/
void Account::print()
{

} // end Account::print()
