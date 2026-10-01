#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    Book(string t = "", string a = "", string i = "")
    {
        title = t;
        author = a;
        ISBN = i;
    }
    void displayBook()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
private:
    string title;
    string author;
    string ISBN;
};

class Library
{
public:
    Library(string n)
    {
        libraryName = n;
        lastBook = listOfBook;
    }
    void addBook(Book b)
    {
        if(lastBook - listOfBook < 10)
        {
            *lastBook = b;
            lastBook++;
        }
        else
        {
            cout << "List of book is full!" << endl;
        }

    }
    void displayLibrary()
    {
        cout << libraryName << "\n\n";
        for(int i = 0; i < (lastBook - listOfBook); i++)
        {
            cout << "Book " << (i+1) << ":" << endl;
            listOfBook[i].displayBook();
            cout << endl;
        }
    }
private:
    string libraryName;
    Book listOfBook[10];
    Book * lastBook;
};

int main()
{
    Library myLibrary("NCKU Library");
    myLibrary.addBook(Book("C++ Programming", "Bjarne Stroustrup", "9780321563842"));
    myLibrary.addBook(Book("Data Structures", "Nicola Lacey", "9780131986190"));
    myLibrary.addBook(Book("Algorithm Design", "Jon Kleinberg", "9780321295354"));
    myLibrary.addBook(Book("Operating Systems", "Andrew S. Tanenbaum", "9780133591620"));
    myLibrary.addBook(Book("Computer Networks", "Andrew S. Tanenbaum", "9780132126953"));
    myLibrary.displayLibrary();
}
