#include <iostream>
using namespace std;

class Date
{
public:
    Date(int m = 1, int d = 1, int y = 1);

    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int getMonth();
    int getDay();
    int getYear();

    void displayDate();
private:
    int month;
    int day;
    int year;
};

int main()
{
    Date d1(4, 15, 2024);
    Date d2(17, 10, 2025);

    cout << "Before:" << endl;

    d1.displayDate();
    d2.displayDate();

    d1.setYear(1989);
    d1.setMonth(6);
    d1.setDay(3);

    d2.setMonth(8);

    cout << "\nAfter:" << endl;

    d1.displayDate();
    d2.displayDate();
}

Date::Date(int m, int d, int y)
{
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::setMonth(int m)
{
    month = (m >= 1 && m <= 12) ? m : 1;
}

void Date::setDay(int d)
{
    day = d;
}

void Date::setYear(int y)
{
    year = y;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

int Date::getYear()
{
    return year;
}

void Date::displayDate()
{
    cout <<  month << "/" << day << "/" << year << endl;
}
