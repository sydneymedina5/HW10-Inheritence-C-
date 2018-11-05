/*
Author: Sydney Medina
Compiler: GCC set according to the CodeBlocks Notes
Date: 4/18/2018
Purpose of program: Make multiple accounts whether they be a premium account or a regular account
using inheritance from the Account class
Ask the user to create a regular account or a premium account, and then they can either withdraw or
deposit money into these accounts.
*/

#include <iostream>
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"
#include <iomanip>

using namespace std;

int main()
{
    // How much each array can hold
    const int MAX_NUM_REGULAR_ACCOUNTS = 5;
    const int MAX_NUM_PREMIUM_ACCOUNTS = 5;

    // Object array
    RegularAccount * regularAccountArray[MAX_NUM_REGULAR_ACCOUNTS];
    PremiumAccount * premiumAccountArray[MAX_NUM_PREMIUM_ACCOUNTS];

    // Set equal to null
    for(int i = 0; i < MAX_NUM_REGULAR_ACCOUNTS; i++)
    {
        regularAccountArray[i] = nullptr;
    }

    // Set equal to null
    for(int i = 0; i < MAX_NUM_PREMIUM_ACCOUNTS; i++)
    {
        premiumAccountArray[i] = nullptr;
    }


    string ownerNam; // for user to enter owner name and pass to functions
    double amnt; //  for user to enter amount and pass to functions
    int userChoice; // for user to enter what choice they would like
    int arrayIndexReg = 0; // keep track of how many regular accounts made
    int arrayIndexPrem = 0; // keep track of how many premium accounts made
    int position = -1; // looking for if account exists
    int accountNum; // for user to enter account number

    // Menu
    do
    {
        cout << left << setw(50) << "1 -> Create regular account" << "2 -> Create premium account" << endl;
        cout << setw(50) << "3 -> Deposit to regular account" << "4 -> Deposit to premium account" << endl;
        cout << setw(50) << "5 -> Withdraw from regular account" << "6 -> Withdraw from premium account" << endl;
        cout << setw(50) << "7 -> Display information for all accounts" << "8 -> Quit" << endl;

        cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                    if(arrayIndexReg >= 5)
                    {
                        cout << "Max number of accounts have been reached" << endl << endl;
                        break;
                    }
                    cout << "Enter owner's name: ";
                    cin.ignore();
                    getline(cin, ownerNam);
                    cout << "Enter amount: ";
                    cin >> amnt;

                    regularAccountArray[arrayIndexReg] = new RegularAccount(ownerNam, amnt); // For a regular account

                    cout << "Regular Account #" << regularAccountArray[arrayIndexReg]->getAccountNumber();
                    cout << " created" << endl << endl;

                    arrayIndexReg++;
                break;

            case 2:
                    if(arrayIndexPrem >= 5)
                    {
                        cout << "Max number of accounts have been reached" << endl << endl;
                        break;
                    }

                    cout << "Enter owner's name: ";
                    cin.ignore();
                    getline(cin, ownerNam);
                    cout << "Enter amount: ";
                    cin >> amnt;

                    if(amnt < 1000)
                    {
                        cout << "Insufficient amount, you need at least $1000.00 to open a premium account" << endl << endl;
                        break;
                    }

                    premiumAccountArray[arrayIndexPrem] = new PremiumAccount(ownerNam, amnt); // For a premium account

                    cout << "Premium Account # " << premiumAccountArray[arrayIndexPrem]->getAccountNumber();
                    cout << " created" << endl << endl;

                    arrayIndexPrem++;
                break;

            case 3: cout << "Enter account number: ";
                    cin >> accountNum;

                    position = -1;

                    for(int i = 0; i < arrayIndexReg; i++)
                    {
                        if(regularAccountArray[i]->getAccountNumber() == accountNum)
                            position = i;
                    }

                    if(position == -1)
                    {
                        cout << "No such account" << endl << endl;
                        break;
                    }

                    cout << "Enter amount: $";
                    cin >> amnt;
                    if(!regularAccountArray[position]->deposit(amnt))
                    {
                        cout << "Deposit amount cannot be negative, deposit not executed" << endl << endl;
                        break;
                    }

                    cout << "New balance is $" << setprecision(2) << fixed << regularAccountArray[position]->getBalance();
                    cout << endl << endl;
                break;

            case 4: cout << "Enter account number: ";
                    cin >> accountNum;

                    position = -1;

                    for(int i = 0; i < arrayIndexPrem; i++)
                    {
                        if(premiumAccountArray[i]->getAccountNumber() == accountNum)
                            position = i;
                    }

                    if(position == -1)
                    {
                        cout << "No such account" << endl << endl;
                        break;
                    }

                    cout << "Enter amount: $";
                    cin >> amnt;
                    if(!premiumAccountArray[position]->deposit(amnt))
                    {
                        cout << "Deposit amount cannot be negative, deposit not executed" << endl << endl;
                        break;
                    }

                    cout << "New balance is $" << setprecision(2) << fixed << premiumAccountArray[position]->getBalance();
                    cout << endl << endl;
                break;

            case 5: cout << "Enter account number: ";
                    cin >> accountNum;

                    position = -1;

                    for(int i = 0; i < arrayIndexReg; i++)
                    {
                        if(regularAccountArray[i]->getAccountNumber() == accountNum)
                            position = i;
                    }

                    if(position == -1)
                    {
                        cout << "No such account" << endl << endl;
                        break;
                    }

                    cout << "Enter amount: $";
                    cin >> amnt;

                    if(!regularAccountArray[position]->withdraw(amnt))
                    {
                        cout << "Insufficient balance, withdraw not executed";
                        cout << endl << endl;
                        break;
                    }

                    cout << "New balance is $" << setprecision(2) << fixed << regularAccountArray[position]->getBalance();
                    cout << endl << endl;
                break;

            case 6: cout << "Enter account number: ";
                    cin >> accountNum;

                    position = -1;

                    for(int i = 0; i < arrayIndexPrem; i++)
                    {
                        if(premiumAccountArray[i]->getAccountNumber() == accountNum)
                            position = i;
                    }

                    if(position == -1)
                    {
                        cout << "No such account" << endl << endl;
                        break;
                    }

                    cout << "Enter amount: $";
                    cin >> amnt;

                    if(!premiumAccountArray[position]->withdraw(amnt))
                    {
                        cout << "You need to maintain a min balance of $1000.00, withdraw not executed";
                        cout << endl << endl;
                        break;
                    }

                    cout << "New balance is $" << setprecision(2) << fixed << premiumAccountArray[position]->getBalance();
                    cout << endl << endl;
                break;

            case 7: for(int i = 0; i < arrayIndexReg; i++)
                    {
                        regularAccountArray[i]->print();
                    }

                    cout << endl;

                    for(int i = 0; i < arrayIndexPrem; i++)
                    {
                        premiumAccountArray[i]->print();
                    }

                    cout << endl;

                break;

            case 8:
                break;

            default:
                cout << "Enter in a different choice" << endl;
                break;
        }
    }while(userChoice != 8);
    return 0;
} // end main()
