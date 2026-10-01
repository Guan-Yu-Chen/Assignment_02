#include <iostream>
using namespace std;

const int DIRECTORY_SIZE = 5;
const char *names[DIRECTORY_SIZE] = {"user01", "user02", "user03", "user04", "user05"};
const char *phoneNumbers[DIRECTORY_SIZE] = {"0955123001", "0955123002", "0955123003", "0955123004", "0955123005"};

void printDirectory();
void findPhoneNumber(const char *);
void updatePhoneNumber(const char *, const char *);
void showMenu();

int main()
{
    bool isProgramRunning = 1;
    char input[100];
    showMenu();
    while(isProgramRunning)
    {
        cout << "Please give the order:";
        cin.getline(input, sizeof(input));

        if(*(input) == '1')
        {
            cout << "> Print the Directory <" << endl;
            printDirectory();
            cout << "==============================" << endl;
        }
        else if(*(input) == '2')
        {
            cout << "> Find a Phone Number <" << endl;
            char name[100];
            cout << "Please enter a name in the directory:";
            cin.getline(name, sizeof(name));
            findPhoneNumber(name);
            cout << "==============================" << endl;
        }
        else if(*(input) == '3')
        {
            cout << "> Update a Phone Number <" << endl;
            char name[100];
            char newNumber[100];
            cout << "Please enter a name in the directory:";
            cin.getline(name, sizeof(name));
            cout << "Please enter the new phone number:";
            cin.getline(newNumber, sizeof(newNumber));
            updatePhoneNumber(name, newNumber);
            cout << "==============================" << endl;
        }
        else if(*(input) == '0')
        {
            isProgramRunning = 0;
        }
        else
        {
            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}

void showMenu()
{
    cout << "------------------------------" << endl;
    cout << "\tMenu" << endl;
    cout << "1 : Print the Directory" << endl;
    cout << "2 : Find a Phone Number" << endl;
    cout << "3 : Update a Phone Number" << endl;
    cout << "0 : Quit the Program" << endl;
    cout << "------------------------------" << endl;
}

void printDirectory()
{
    cout << "Names" << "\t" << "PhoneNumbers" << endl;
    for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
    {
        cout << names[i] << "\t" << phoneNumbers[i] << endl;
    }
}

void findPhoneNumber(const char *name)
{
    bool isNameInDirectory;
    int size = 0;
    for(int i = 0 ; *(name + i) != '\0' ; i++)
    {
        size++;
    }

    for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
    {
        isNameInDirectory = 1;
        for(int j = 0 ; j < (size + 1) ; j++)
        {
            if(*(name + j) != *(*(names + i) + j))
            {
                isNameInDirectory = 0;
                break;
            }
        }
        if(isNameInDirectory)
        {
            cout << name << "\'s phone number is " << phoneNumbers[i] << endl;
            break;
        }
    }
    if(!isNameInDirectory)
    {
        cout << name << " is not in the directory!" << endl;
    }
}
void updatePhoneNumber(const char *name, const char *newNumber)
{
    bool isNameInDirectory;
    int size = 0;
    for(int i = 0 ; *(name + i) != '\0' ; i++)
    {
        size++;
    }

    for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
    {
        isNameInDirectory = 1;
        for(int j = 0 ; j < (size + 1) ; j++)
        {
            if(*(name + j) != *(*(names + i) + j))
            {
                isNameInDirectory = 0;
                break;
            }
        }
        if(isNameInDirectory)
        {
            phoneNumbers[i] = newNumber;
            cout << name << "\'s phone number updated!" << endl;
            break;
        }
    }
    if(!isNameInDirectory)
    {
        cout << name << " is not in the directory!" << endl;
    }
}
