#include <iostream>
#include <string>
using namespace std;

class HugeInteger
{
public:
    HugeInteger();
    void input();
    void output();
    void add(string);
    void add(HugeInteger);
    void subtract(string);
    void subtract(HugeInteger);
    int* getNumber();

private:
    int number[40];
};

bool isEqualTo(HugeInteger num1, HugeInteger num2);
bool isGreaterThan(HugeInteger num1, HugeInteger num2);
bool isLessThan(HugeInteger num1, HugeInteger num2);
bool isGreaterThanOrEqualTo(HugeInteger num1, HugeInteger num2);
bool isLessThanOrEqualTo(HugeInteger num1, HugeInteger num2);
bool isZero(HugeInteger num1);

int main()
{
    HugeInteger x;
    HugeInteger y;

    cout << "Set X: ";
    x.input();
    cout << "\nSet Y: ";
    y.input();
    cout << endl;
    
    cout << "X = ";
    x.output();
    cout << "Y = ";
    y.output();
    cout << endl;

    cout << "X + Y = ";
    x.add(y);
    cout << "X - Y = ";
    x.subtract(y);

    cout << "Y + X = ";
    y.add(x);
    cout << "Y - X = ";
    y.subtract(x);
    cout << endl;
    
    cout << "X = Y : " << ((isEqualTo(x, y))? "True" : "False") << endl;
    cout << "X > Y : " << ((isGreaterThan(x, y))? "True" : "False") << endl;
    cout << "X < Y : " << ((isLessThan(x, y))? "True" : "False") << endl;
    cout << "X >= Y : " << ((isGreaterThanOrEqualTo(x, y))? "True" : "False") << endl;
    cout << "X <= Y : " << ((isLessThanOrEqualTo(x, y))? "True" : "False") << endl;
    cout << "X = 0 : " << ((isZero(x))? "True" : "False") << endl;
    cout << "Y = 0 : " << ((isZero(y))? "True" : "False") << endl;
    
}


HugeInteger::HugeInteger()
{
    for(int i = 0; i < 40; i++)
    {
        number[i] = 0;
    }
}

void HugeInteger::input() //enter a string and convert to int array, check if wrong input
{
    string input;
    bool isInputCorrect = 0;
    while(!isInputCorrect)
    {
        getline(cin, input);
        for(int i = 0; i < int(input.length()); i++)
        {
            if(int(input[i]) < 48 || int(input[i]) > 57)
            {
                cout << "Wrong input!\nPlease enter again:";
                break;
            }
            else
                number[i] = int(input[input.length()-i-1]) - 48;
        }
        isInputCorrect = 1;
    }
}

void HugeInteger::output()
{
    bool isFirstDigitZero = 1;
    for(int i = 0; i < 40; i++)
    {
        if(!number[39-i] && isFirstDigitZero)
            continue;
        else
        {
            isFirstDigitZero = 0;
            cout << number[39-i];
        }
    }
    cout << endl;
}

void HugeInteger::add(string input)
{
    int result[41] = {};
    int num1, num2;
    for(int i = 0; i < 40; i++)
    {
        num1 = number[i];
        num2 = (int(input.length()-i-1) < 0) ? 0 : int(input[input.length()-i-1])-48;
        result[i] += num1 + num2;
        if(result[i] >= 10)
        {
            result[i+1]++;
            result[i] %= 10;
        }
    }
    bool isFirstDigitZero = 1;
    for(int i = 0; i < 41; i++)
    {
        if(!result[40-i] && isFirstDigitZero)
            continue;
        else
        {
            isFirstDigitZero = 0;
            cout << result[40-i];
        }
    }
    cout << endl;
}

void HugeInteger::add(HugeInteger another)
{
    int result[41] = {};
    int num1, num2;
    for(int i = 0; i < 40; i++)
    {
        num1 = number[i];
        num2 = another.number[i];
        result[i] += num1 + num2;
        if(result[i] >= 10)
        {
            result[i+1]++;
            result[i] %= 10;
        }
    }
    bool isFirstDigitZero = 1;
    for(int i = 0; i < 41; i++)
    {
        if(!result[40-i] && isFirstDigitZero)
            continue;
        else
        {
            isFirstDigitZero = 0;
            cout << result[40-i];
        }
    }
    cout << endl;
}

void HugeInteger::subtract(string input)
{    
    int result[41] = {};
    int num1[40];
    int num2[40];
    bool isNum1Greater = 1;
    for(int i = 0; i < 40; i++)
    {
        num1[i] = number[i];
        num2[i] = (int(input.length()-i-1) < 0) ? 0 : int(input[input.length()-i-1])-48;
    }
    for(int i = 0; i < 40; i++)
    {
        if(num1[39-i] > num2[39-i])
        {
            isNum1Greater = 1;
            break;
        }
        else if(num1[39-i] == num2[39-i])
            continue;
        else
        {
            isNum1Greater = 0;
            break;
        }
    }

    if(isNum1Greater)
    {
        for(int i = 0; i < 40; i++)
        {
            result[i] += num1[i] - num2[i];
            if(result[i] < 0)
            {
                result[i] += 10;
                result[i+1]--;
            }
        }
        bool isFirstDigitZero = 1;
        for(int i = 0; i < 41; i++)
        {
            if(!result[40-i] && isFirstDigitZero)
                continue;
            else
            {
                isFirstDigitZero = 0;
                cout << result[40-i];
            }
        }
        cout << endl;
    }
    else
    {
        for(int i = 0; i < 40; i++)
        {
            result[i] += num2[i] - num1[i];
            if(result[i] < 0)
            {
                result[i] += 10;
                result[i+1]--;
            }
        }
        cout << "-";
        bool isFirstDigitZero = 1;
        for(int i = 0; i < 41; i++)
        {
            if(!result[40-i] && isFirstDigitZero)
                continue;
            else
            {
                isFirstDigitZero = 0;
                cout << result[40-i];
            }
        }
        cout << endl;
    }
}

void HugeInteger::subtract(HugeInteger another)
{
    int result[41] = {};
    int num1[40];
    int num2[40];
    bool isNum1Greater = 1;
    for(int i = 0; i < 40; i++)
    {
        num1[i] = number[i];
        num2[i] = another.number[i];
    }
    for(int i = 0; i < 40; i++)
    {
        if(num1[39-i] > num2[39-i])
        {
            isNum1Greater = 1;
            break;
        }
        else if(num1[39-i] == num2[39-i])
            continue;
        else
        {
            isNum1Greater = 0;
            break;
        }
    }

    if(isNum1Greater)
    {
        for(int i = 0; i < 40; i++)
        {
            result[i] += num1[i] - num2[i];
            if(result[i] < 0)
            {
                result[i] += 10;
                result[i+1]--;
            }
        }
        bool isFirstDigitZero = 1;
        for(int i = 0; i < 41; i++)
        {
            if(!result[40-i] && isFirstDigitZero)
                continue;
            else
            {
                isFirstDigitZero = 0;
                cout << result[40-i];
            }
        }
        cout << endl;
    }
    else
    {
        for(int i = 0; i < 40; i++)
        {
            result[i] += num2[i] - num1[i];
            if(result[i] < 0)
            {
                result[i] += 10;
                result[i+1]--;
            }
        }
        cout << "-";
        bool isFirstDigitZero = 1;
        for(int i = 0; i < 41; i++)
        {
            if(!result[40-i] && isFirstDigitZero)
                continue;
            else
            {
                isFirstDigitZero = 0;
                cout << result[40-i];
            }
        }
        cout << endl;
    }
}

int* HugeInteger::getNumber()
{
    return number;
}
    
bool isEqualTo(HugeInteger num1, HugeInteger num2)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[i] != num2.getNumber()[i])
            return false;
    }
    return true;
}

bool isGreaterThan(HugeInteger num1, HugeInteger num2)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[39-i] == num2.getNumber()[39-i])
            continue;
        else if(num1.getNumber()[39-i] > num2.getNumber()[39-i])
            return true;
        else
            return false;
    }
}

bool isLessThan(HugeInteger num1, HugeInteger num2)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[39-i] == num2.getNumber()[39-i])
            continue;
        else if(num1.getNumber()[39-i] < num2.getNumber()[39-i])
            return true;
        else
            return false;
    }
}

bool isGreaterThanOrEqualTo(HugeInteger num1, HugeInteger num2)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[39-i] == num2.getNumber()[39-i])
            continue;
        else if(num1.getNumber()[39-i] > num2.getNumber()[39-i])
            return true;
        else
            return false;
    }
    return 1;
}

bool isLessThanOrEqualTo(HugeInteger num1, HugeInteger num2)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[39-i] == num2.getNumber()[39-i])
            continue;
        else if(num1.getNumber()[39-i] < num2.getNumber()[39-i])
            return true;
        else
            return false;
    }
    return true;
}

bool isZero(HugeInteger num1)
{
    for(int i = 0; i < 40; i++)
    {
        if(num1.getNumber()[i] != 0)
            return false;
    }
    return true;
}
