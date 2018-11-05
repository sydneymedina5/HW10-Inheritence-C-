# HW10-Inheritence-C++
This homework assignment gives you the opportunity to practice inheritance

# 1. Account class
Account has the following member variables:
private:
- accountNumber of type int
- ownerName of type string

protected:
- balance of type double
- numberAccounts of type static int, initialized to zero 

and the following member functions:
public:
- Account(ownerName_, balance_) is the constructor that initializes the account’s
member variables ownerName and balance. balance_ is the amount deposited when the
account is created. accountNumber is set to (numberAccounts+1000) and
numberAccounts is incremented.
- withdraw(amount) function to withdraw a specified amount from the account. The function
should first check if there is sufficient balance in the account. If the balance is sufficient,
withdrawal is processed. Otherwise the withdrawal is not made. If the withdrawal is made, the
withdrawal amount is deducted from balance.
- deposit(amount) function to deposit a specified amount of money to the account. The
function should first check if the deposit amount is positive. If it is positive, deposit is processed.
Otherwise the deposit is not made. If the deposit is made, the amount is added to balance.
- getAccountNumber(): An accessor function that returns the account number.
- getBalance(): An accessor function that returns the account balance. .
- getNumberAccounts(): A static member function that returns numberAccounts.
- print(): a virtual member function that prints accountNumber, ownerName,
balance.

# 2. RegularAccount class
Implement a RegularAccount class that is derived from the Account class.
In addition to the inherited members, it has the following private member variables:
- numberRegularAccounts of type static int, initialized to zero
and the following public member functions:
- RegularAccount(name, amount) is the constructor which increments
numberRegularAccounts and passes the arguments to the Account constructor
- getNumberRegularAccounts(): A static member function that returns
numberRegularAccounts.
- print(): overrides the print() of Account. This function prints the string “Regular
account” then prints accountNumber, ownerName, balance. To print the
accountNumber, ownerName, balance, call the print function of Account with
this statement: this->Account::print();

# 3. PremiumAccount class
Implement a PremiumAccount class that is derived from the Account class.
In addition to the inherited members, it has the following private member variables:
- numberPremiumAccounts of type static int, initialized to zero
- MIN_BALANCE of type static double, initialized to 1000. The customer of a premium
account is required to maintain a balance of at least MIN_BALANCE dollars.

and the following public member functions:
- PremiumAccount(name, amount) is the constructor which increments
numberPremiumAccounts and passes the arguments to the Account constructor
- getNumberPremiumAccounts(): A static member function that returns
numberPremiumAccounts.
- redefined withdraw(amount) function to withdraw a specified amount from the account.
The function should first check if the existing balance is greater or equal to the withdrawal
amount + MIN_BALANCE. If so, withdrawal is processed. Otherwise the withdrawal is not made.
If the withdrawal is made, the withdrawal amount is deducted from balance.
- getMinBalance():A static member function that returns MIN_BALANCE
- print(): overrides the print() of Account. This function prints the string “Premium
account” then prints accountNumber, ownerName, balance. To print the
accountNumber, ownerName, balance, call the print function of Account with
this statement: this->Account::print();

# 4. Driver for the RegularAccount and PremiumAccount classes (in main function)
For consistency in the submissions to make the grading task more efficient, use this pseudocode:
const int MAX_NUM_REGULAR_ACCOUNTS = 5;
const int MAX_NUM_PREMIUM_ACCOUNTS = 5;
// Define two arrays of pointers:
RegularAccount * regularAccountArray[MAX_NUM_REGULAR_ACCOUNTS];
PremiumAccount * premiumAccountArray[MAX_NUM_PREMIUM_ACCOUNTS];
Loop on displaying the following menu of choices:
1. Create regular account (user will be prompted for name, amount)
2. Create premium account (user will be prompted for name,amount)
3. Deposit to regular account (user will be prompted for account
number, amount)
4. Deposit to premium account (user will be prompted for account
number, amount)
5. Withdraw from regular account (user will be prompted for account
number, amount)
6. Withdraw from premium account (user will be prompted for account
number, amount)
7. Display information for all accounts, regular and premium (type
of account: regular or premium, accountNumber, ownerName,
balance)
8. Quit

# 5. Account creation
When an account is created, an object of the corresponding class should be dynamically created,
and the address stored in the appropriate array
- regularAccountArray[arrayIndex] = new RegularAccount(ownerNam,
amnt); // For a regular account
- premiumAccountArray[arrayIndex] = new PremiumAccount(ownerNam,
amnt); // For a premium account
