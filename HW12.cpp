#include <iostream>
using namespace std;

class Vehicle
{
private:
    int speed;
    int fuel;
public:
    Vehicle(int speed, int fuel)
    {
        this->speed = speed;
        this->fuel = fuel;
    }

    void setSpeed(const int & speed)
    {
        this->speed = speed;
    }

    void setFuel(const int & fuel)
    {
        this->fuel = fuel;
    }

    int getFuel() const
    {
        return this->fuel;
    }

    int getSpeed() const
    {
        return this->speed;
    }

    virtual void displayInfo() = 0;
};  

class LandVehicle : public Vehicle
{
protected:
    int numWheels;
public:
    LandVehicle(int speed, int fuel, int numWheels)
    : Vehicle(speed, fuel)
    {
        this->numWheels = numWheels;
    }

    void displayInfo()
    {
        cout << "Land Vehicle - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel() << ", Wheels: " << this->numWheels << endl;
    }
};

class WaterVehicle : public Vehicle
{
protected:
    int numEngines;
public:
    WaterVehicle(int speed, int fuel, int numEngines)
    : Vehicle(speed, fuel)
    {
        this->numEngines = numEngines;
    }

    void displayInfo()
    {
        cout << "Water Vehicle - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel() << ", Engines: " << this->numEngines << endl;
    }
};

class AirVehicle : public Vehicle
{
protected:
    int numWings;
public:
    AirVehicle(int speed, int fuel, int numWings)
    : Vehicle(speed, fuel)
    {
        this->numWings = numWings;
    }

    void displayInfo()
    {
        cout << "Air Vehicle - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel() << ", Wings: " << this->numWings << endl;
    }
};

class Car : public LandVehicle
{
protected:
    int numDoors;
public:
    Car(int speed, int fuel, int numWheels, int numDoors)
    : LandVehicle(speed, fuel, numWheels)
    {
        this->numDoors = numDoors;
    }

    void displayInfo()
    {
        cout << "Car - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel()
             << ", Wheels: " << this->numWheels << ", Doors: " << this->numDoors << endl;
    }
};

class Boat : public WaterVehicle
{
protected:
    int numSails;
public:
    Boat(int speed, int fuel, int numEngines, int numSails)
    : WaterVehicle(speed, fuel, numEngines)
    {
        this->numSails = numSails;
    }

    void displayInfo()
    {
        cout << "Boat - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel()
             << ", Engines: " << this->numEngines << ", Sails: " << this->numSails << endl;
    }
};

class Plane : public AirVehicle
{
protected:
    int numEngines;
public:
    Plane(int speed, int fuel, int numWings, int numEngines)
    : AirVehicle(speed, fuel, numWings)
    {
        this->numEngines = numEngines;
    }
    
    void displayInfo()
    {
        cout << "Plane - Speed: " << this->getSpeed() << ", Fuel: " << this->getFuel()
             << ", Wings: " << this->numWings << ", Engines: " << this->numEngines << endl;
    }
};

int main()
{
    LandVehicle landVehicle(80, 50, 4);
    WaterVehicle waterVehicle(60, 40, 2);
    AirVehicle airVehicle(300, 200, 2);
    Car car(120, 60, 4, 4);
    Boat boat(40, 30, 1, 2);
    Plane plane(600, 300, 2, 4);

    Vehicle * landVPtr = &landVehicle;
    Vehicle * waterVPtr = &waterVehicle;
    Vehicle * airVPtr = &airVehicle;
    Vehicle * carPtr = &car; 
    Vehicle * boatPtr = &boat; 
    Vehicle * planePtr = &plane;

    landVPtr->displayInfo();
    waterVPtr->displayInfo();
    airVPtr->displayInfo();
    carPtr->displayInfo();
    boatPtr->displayInfo();
    planePtr->displayInfo();

    cout << "\nDiagram:" << endl;
    cout << "\t\tVehicle" << endl;
    cout << "\t\t|" << endl;
    cout << "---------------------------------" << endl;
    cout << "|\t\t|\t\t|" << endl;
    cout << "LandVehicle\tWaterVehicle\tAirVehicle" << endl;
    cout << "|\t\t|\t\t|" << endl;
    cout << "Car\t\tBoat\t\tPlane" << endl;
}
