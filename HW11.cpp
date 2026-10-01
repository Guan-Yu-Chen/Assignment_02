#include <iostream>
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
    
    void credit(double money)
    {
        this->balance += money;
    }

    bool debit(double money)
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

    void debit(double money)
    {
        if(Account::debit(money))
        {
            Account::debit(this->fee);
        }
    }
};

int main() {
    // Testing Account class
    Account acc(100.0);
    std::cout << "Account balance: " << acc.getBalance() << std::endl;
    acc.credit(50.0);
    std::cout << "Account balance after credit: " << acc.getBalance() << std::endl;
    acc.debit(30.0);
    std::cout << "Account balance after debit: " << acc.getBalance() << std::endl;

    // Testing SavingsAccount class
    SavingsAccount savings(500.0, 0.05); // Initial balance $500, interest rate 5%
    std::cout << "Savings account balance: " << savings.getBalance() << std::endl;
    double interest = savings.calculateInterest();
    savings.credit(interest);
    std::cout << "Savings account balance after interest: " << savings.getBalance() << std::endl;

    // Testing CheckingAccount class
    CheckingAccount checking(200.0, 1.0); // Initial balance $200, transaction fee $1
    std::cout << "Checking account balance: " << checking.getBalance() << std::endl;
    checking.credit(100.0);
    std::cout << "Checking account balance after credit: " << checking.getBalance() << std::endl;
    checking.debit(50.0);
    std::cout << "Checking account balance after debit: " << checking.getBalance() << std::endl;

    return 0;
}
