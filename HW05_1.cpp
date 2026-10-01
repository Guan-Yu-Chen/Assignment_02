#include<iostream>
using namespace std;

class Account
{
public:
    Account();
    void credit();
    void debit();
    void getBalance();
    void placeOrder();

private:
    int balance;
};

int main()
{
    cout << "Input first person's balance:";
    Account person1;
    cout << "Input second person's balance:";
    Account person2;
    cout << endl;

    int person;
    while(true)
    {
        cout << "Choose a person\'s account(1 or 2):";
        cin >> person;
        if(person == 1)
            person1.placeOrder();
        else if(person == 2)
            person2.placeOrder();
        else
            cout << "Wrong input!" << endl;
    }

}

Account::Account()
{
    cin >> balance;
    if(balance < 0)
        cout << "Initial balance was invalid. Current balance setted to $0" << endl;
    balance = (balance >= 0) ? balance : 0;
}

void Account::credit()
{
    int addMoney;
    cout << "Enter the amount of maoney to add:";
    cin >> addMoney;
    balance += addMoney;
    cout << "$" << addMoney << " added to current balance." << endl;
    getBalance();
}

void Account::debit()
{
    int withdrawMoney;
    cout << "Enter the amount of money to debit:";
    cin >> withdrawMoney;
    if(withdrawMoney > balance)
        cout << "Debit amount exceeded account balance." << endl;
    else
    {
        balance -= withdrawMoney;
        cout << "$" << withdrawMoney << " withdraw from the account.";
    }
    getBalance();
}


void Account::getBalance()
{
    cout << "Current balance: " << balance << endl;
}

void Account::placeOrder()
{
    int order = 1;
    cout << "0. Choose another person" << endl;
    cout << "1. Add money to the account" << endl;
    cout << "2. Withdraw money from the account" << endl;
    cout << "3. Print the current balance\n" << endl;
    while(order != 0)
    {
        cout << "Place your order:";
        cin >> order;
        if(order == 1)
            credit();
        else if(order == 2)
            debit();
        else if(order == 3)
            getBalance();
        else if(order == 0)
            continue;
        else
            cout << "Wrong input!" << endl;
        cout << endl;
    }
}
