#include <iostream>
#include <string>
using namespace std;

class Package
{
public:
    Package(const string& n1, const string& a1, const string& c1, const string& s1, const string& z1, 
            const string& n2, const string& a2, const string& c2, const string& s2, const string& z2, double w, double cost)
            : senderName(n1), senderAddress(a1), senderCity(c1), senderState(s1), senderZipCode(z1),
                recipientName(n2), recipientAddress(a2), recipientCity(c2), recipientState(s2), recipientZipCode(z2)
            {
                weight = (w > 0) ? w : 0;
                costPerOunce = (cost > 0) ? cost : 0;
            }
    double calculateCost()
    {
        return weight * costPerOunce;
    }

    string getSenderName()
    {
        return senderName;
    }

    string getSenderAddress()
    {
        return senderAddress;
    }

    string getSenderCity()
    {
        return senderCity;
    }

    string getSenderState()
    {
        return senderState;
    }

    string getSenderZipCode()
    {
        return senderZipCode;
    }

    string getRecipientName()
    {
        return recipientName;
    }

    string getRecipientAddress()
    {
        return recipientAddress;
    }

    string getRecipientCity()
    {
        return recipientCity;
    }

    string getRecipientState()
    {
        return recipientState;
    }

    string getRecipientZipCode()
    {
        return recipientZipCode;
    }

    double getWeight()
    {
        return weight;
    }

    double getCostPerOunce()
    {
        return costPerOunce;
    }

private:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZipCode;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZipCode;

    double weight;
    double costPerOunce;
};

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(
        const string& n1, const string& a1, const string& c1, const string& s1, const string& z1, 
        const string& n2, const string& a2, const string& c2, const string& s2, const string& z2, 
        double w, double cost , double fee) 
        : Package(n1, a1, c1, s1, z1, n2, a2, c2, s2, z2, w, cost)
    {
        flatFee = fee;
    }

    double calculateCost()
    {
        return Package::calculateCost() + flatFee;
    }
private:
    double flatFee;
};

class OvernightPackage : public Package
{
public:
    OvernightPackage(
        const string& n1, const string& a1, const string& c1, const string& s1, const string& z1, 
        const string& n2, const string& a2, const string& c2, const string& s2, const string& z2, 
        double w, double cost , double fee) 
        : Package(n1, a1, c1, s1, z1, n2, a2, c2, s2, z2, w, cost)
    {
        additionalFee = fee;
    }

    double calculateCost()
    {
        return getWeight() * (getCostPerOunce() + additionalFee);
    }
private:
    double additionalFee;
};

int main()
{
    // Test program
    // Create a Package object
    Package package("John Doe", "123 Main St", "Anytown", "CA", "12345",
                    "Jane Smith", "456 Elm St", "Othertown", "NY", "54321",
                    10, 0.5);
    std::cout << "Package shipping cost: $" << package.calculateCost() << std::endl;

    // Create a TwoDayPackage object
    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", 
                                "Jane Smith", "456 Elm St", "Othertown", "NY", "54321", 
                                10, 0.5, 5);
    std::cout << "Two-day package shipping cost: $" << twoDayPackage.calculateCost() << std::endl;

    // Create an OvernightPackage object
    OvernightPackage overnightPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", 
                                      "Jane Smith", "456 Elm St", "Othertown", "NY", "54321", 
                                      10, 0.5, 2);
    std::cout << "Overnight package shipping cost: $" << overnightPackage.calculateCost() << std::endl;

    return 0;
}
