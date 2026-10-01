#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class HourError : public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid hour";
    }
};

class MinuteError : public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid minute";
    }
};

class SecondError : public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid second";
    }
};

class ProductNotFoundException : public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid product ID";
    }
};

int testCases[][3] = { 
    {14, 30, 45},
    {23, 59, 59},
    {24, 0, 0},
    {12, 60, 0},
    {12, 30, 60},
    {25, 60, 20},
    {26, 70, 60}
};

void convertTime(int testCases[][3], int i)
{
    try
    {
        if(testCases[i][0] < 0 || testCases[i][0] > 23)
            throw HourError();
        else if(testCases[i][1] < 0 || testCases[i][1] > 59)
            throw MinuteError();
        else if(testCases[i][2] < 0 || testCases[i][2] > 59)
            throw SecondError();
        else
        {
            cout << testCases[i][0] << " hours, " << testCases[i][1] << " minutes, and " << testCases[i][2] << " seconds." << endl;
        }
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
    }
}

int getProductID(int ids[], string names[], int numProducts, string target) 
{ 
    for (int i = 0; i < numProducts; i++) 
    { 
        if (names[i] == target) 
            return ids[i]; 
    } 
    throw ProductNotFoundException();
}

int main()
{
    cout << "Q1\n";
    for(int i = 0; i < 7; i++)
    {
        convertTime(testCases, i);
    }

    cout << "\n\n\n";
    cout << "Q2\n";

    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};

    try
    {
        cout << "Product ID: " << getProductID(productIds, products, 5, "mouse") << endl;
        cout << "Product ID: " << getProductID(productIds, products, 5, "camera") << endl;
        cout << "Product ID: " << getProductID(productIds, products, 5, "laptop") << endl;
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
    }
    
}
