#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
    Time(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void printUniveral();
    void printStandard();
    void tick();
private:
    int hour;
    int minute;
    int second;
};

int main()
{
    Time t1(22, 58, 59);

    cout << "Now time:" << endl;
    t1.printStandard();
    cout << endl;
    t1.printUniveral();
    cout << "\n\n";

    t1.tick();
    
    cout << "After one second:" << endl;
    t1.printStandard();
    cout << endl;
    t1.printUniveral();
    cout << "\n\n";

    for(int i = 0; i < 60; i++)
    {
        t1.tick();
    }
    
    cout << "After one minute:" << endl;
    t1.printStandard();
    cout << endl;
    t1.printUniveral();
    cout << "\n\n";

    for(int i = 0; i < 3600; i++)
    {
        t1.tick();
    }

    cout << "After one hour:" << endl;
    t1.printStandard();
    cout << endl;
    t1.printUniveral();
    cout << "\n\n";
}

Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniveral()
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard()
{
    cout << setfill('0') << setw(2) << ((hour == 0 || hour == 12) ? 12 : hour%12) << ":"
            << setw(2) << minute << ":" << setw(2) << second << ((hour >= 12) ? " PM" : " AM");
}

void Time::tick()
{
    second++;
    if(second == 60)
    {
        second = 0;
        minute ++;
    }
    if(minute == 60)
    {
        minute = 0;
        hour++;
    }
    if(hour == 24)
    {
        hour = 0;
    }
}
