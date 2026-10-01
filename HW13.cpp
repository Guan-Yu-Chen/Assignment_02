#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Account
{
private:
    double balance;
public:
    Account(double balance)
    {
        this->balance = (balance > 0) ? balance : 0;
        if(balance < 0)
        {
            cout << "Initial balance can't be less than 0" << endl;
        }
    }
    
    virtual void credit(double money)
    {
        this->balance += money;
    }

    virtual bool debit(double money)
    {
        if(money > this->balance)
        {
            cout << "Debit amount exceeded account balance." << endl;
        }
        else
        {
            this->balance -= money;
        }
        return this->balance > money;
    }

    double getBalance()
    {
        return this->balance;
    }

    virtual double calculateInterest()
    {
        return 0;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;
public:
    SavingsAccount(double balance, double interestRate)
    : Account(balance)
    {
        this->interestRate = interestRate;
    }

    double calculateInterest()
    {
        return this->getBalance() * this->interestRate;
    }
};

class CheckingAccount : public Account
{
private:
    double fee;
public:
    CheckingAccount(double balance, double fee)
    : Account(balance)
    {
        this->fee = fee;
    }

    void credit(double money)
    {
        Account::credit(money);
        Account::debit(this->fee);
    }

    bool debit(double money)
    {
        if(Account::debit(money))
        {
            Account::debit(this->fee);
        }
    }

};

int main()
{
    std::vector<Account*> accounts;

    // Create SavingsAccount and CheckingAccount objects
    accounts.push_back(new SavingsAccount(500.0, 0.05)); // Savings account with $500 initial balance and 5% interest rate
    accounts.push_back(new CheckingAccount(200.0, 1.0)); // Checking account with $200 initial balance and $1 fee per transaction

    // Process each account
    int money;
    for(Account* account : accounts)
    {
        cout << "Processing " << typeid(*account).name() << " account." << endl;

        cout << "Enter amount to deposit: ";
        cin >> money;
        account->credit(money);

        cout << "Enter amount to withdraw: ";
        cin >> money;
        account->debit(money);

        if(dynamic_cast < SavingsAccount * >(account))
        {
            cout << "Interest added: " << account->calculateInterest() << endl;
            account->credit(account->calculateInterest());
        }

        cout << "Update balance: " << account->getBalance() << endl;

    }
    // Clean up dynamically allocated memory

    for(Account* account : accounts)
    {
        delete account;
    }

    return 0;
}
