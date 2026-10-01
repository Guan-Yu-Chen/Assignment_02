#include <iostream>
#include <string>
using namespace std;

class Invoice
{
public:
    Invoice(string = "", string = "", int = 0, int = 0);
    void placeOrder();
    
private:
    string partNumber;
    string partDescription;
    int quantityPurchased;
    int itemPrice;
    void set();
    void get();
    void getInvoiceAmount();

};

int main()
{
    Invoice item1("AAA-0001", "Nikon Z6II", 20, 66000);
    Invoice item2("AAA-0002", "Sony A74", 30, 62000);

    int item;
    while(true)
    {
        cout << "Choose an item(1 or 2):";
        cin >> item;
        if(item == 1)
            item1.placeOrder();
        else if(item == 2)
            item2.placeOrder();
        else
            cout << "Wrong input!" << endl;
    }
}

Invoice::Invoice(string partN, string partD, int quantityP, int itemP)
{
    partNumber = partN;
    partDescription = partD;
    quantityPurchased = (quantityP > 0) ? quantityP : 0;
    itemPrice = (itemP > 0) ? itemP : 0;
}


void Invoice::placeOrder()
{
    int order = 1;
    cout << "0. Choose another item" << endl;
    cout << "1. Set invoice" << endl;
    cout << "2. Get invoice information" << endl;
    cout << "3. Print the invoice amount\n" << endl;
    while(order != 0)
    {
        cout << "Place your order:";
        cin >> order;
        if(order == 1)
            set();
        else if(order == 2)
            get();
        else if(order == 3)
            getInvoiceAmount();
        else if(order == 0)
            continue;
        else
            cout << "Wrong input!" << endl;
        cout << endl;
    }
}
void Invoice::set()
{
    cout << "Set part number:";
    cin >> partNumber;
    cout << "Set part description:(Please DO NOT enter spaces)";
    cin >> partDescription;
    cout << "Set quantity purchased:";
    cin >> quantityPurchased;
    cout << "Set item price:";
    cin >> itemPrice;
}

void Invoice::get()
{
    cout << "Part number: " << partNumber << endl;
    cout << "Part description: " << partDescription << endl;
    cout << "Quantity purchased: " << quantityPurchased << endl;
    cout << "Item price: " << itemPrice << endl;
}

void Invoice::getInvoiceAmount()
{
    cout << "Invoice amount: " << quantityPurchased * itemPrice << endl;
}
