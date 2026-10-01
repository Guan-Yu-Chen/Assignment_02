#include <iostream>
using namespace std;

const int DIRECTORY_SIZE = 5;
const char* names[DIRECTORY_SIZE] = {"Alice", "Bob", "Charlie", "David", "Eve"};

void showOption();
void printDirectory(const char*[], char* const[], int);
bool isUserInDirectory(const char*[], const char*, int);
bool isTwoStringSame(const char*, const char*);

int main()
{
    char** phoneNumbers = new char*[DIRECTORY_SIZE];
    bool isProgramRunning = true;

    for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
    {
        phoneNumbers[i] = new char[20];
    }
    phoneNumbers[0] = "000-000-0000";
    phoneNumbers[1] = "111-111-1111";
    phoneNumbers[2] = "222-222-2222";
    phoneNumbers[3] = "333-333-3333";
    phoneNumbers[4] = "444-444-4444";
    
    while(isProgramRunning)
    {
        showOption();
        int input;
        cin >> input;
        cin.get();
        if(!input)
        {
            cout << "Goodbye!" << endl;
            isProgramRunning = false;
        }
        else if(input == 1)
        {
            cout << endl;
            printDirectory(names, phoneNumbers, DIRECTORY_SIZE);
        }
        else if(input == 2)
        {
            cout << endl;
            
            char name[100] = {};
            do
            {
                cout << "Please enter a user\'s name:";
                cin.getline(name, sizeof(name));
                if(isUserInDirectory(names, name, DIRECTORY_SIZE))
                    break;
                else
                    cout << "User \"" << name << "\" not exist!" << endl;
            } while (true);

            cout << "Please enter the phone number:";
            char newNumber[20] = {};
            cin.getline(newNumber, sizeof(newNumber));
            //updatePhoneNumber(names, phoneNumbers, DIRECTORY_SIZE, name, newNumber);

            for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
            {
                if(isTwoStringSame(name, names[i]))
                {
                    delete [] phoneNumbers[i];
                    phoneNumbers[i] = new char[20];
                    phoneNumbers[i] = newNumber;
                }
            }
        }
        else
        {
            cout << "Wrong input!" << endl;
        }
        cout << endl;
    }    

    for(int i = 0 ; i < DIRECTORY_SIZE ; i++)
    {
        delete [] phoneNumbers[i];
    }
    delete [] phoneNumbers;

    return 0;
}

void showOption()
{
    cout << "Enter 1 to print the directory." << endl;
    cout << "Enter 2 to update the phone number." << endl;
    cout << "Enter 0 to quit the program." << endl;
    cout << "Your input:";
}

void printDirectory(const char* names[], char* const phoneNumbers[], int directorySize)
{
    cout << "Name" << "\t" << "PhoneNumbers" << endl;
    for(int i = 0 ; i < directorySize ; i++)
    {
        cout << *(names + i) << "\t" << *(phoneNumbers + i) << endl;
    }
}

bool isUserInDirectory(const char* names[], const char* name, const int directorySize)
{
    for(int i = 0 ; i < directorySize ; i++)
    {
        if(isTwoStringSame(name, *(names + i)))
            return true;
    }
    return false;
}


bool isTwoStringSame(const char* str1, const char* str2)
{
    //first parameter is for the name entered by user
    for(int i = 0 ; *(str1 + i) ; i++)
    {
        if((*(str1 + i) != *(str2 + i)))
            return false;            
    }
    return true;
}
