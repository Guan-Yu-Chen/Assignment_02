#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

class Book
{
public:
    Book(string t = "", string a = "", double p = 0)
    {
        title = t;
        author = a;
        price = p;
    }
    Book(const Book &b)
    {
        title = b.title;
        author = b.author;
        price = b.price;
    }
    Book &display();
    Book &sell();
    static int totalSales;
private:
    string title;
    string author;
    double price;
    
};

class Bookstore
{
public:
    Bookstore()
    {
        numOfBooks = 0;
    }
    Bookstore &addBook(Book);
    Bookstore &displayBooks();
    Bookstore &sellBook(int);
private:
    Book booklist[MAX_BOOKS];
    int numOfBooks;
};

int Book::totalSales = 0;

Book &Book::display()
{
    cout << "Name: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Price: " << price << endl;
    return *this;
}

Book &Book::sell()
{
    totalSales++;
    cout << "Sell \"" << title << "\"" << endl;
    return *this;
}

Bookstore &Bookstore::addBook(Book book)
{
    booklist[numOfBooks++] = book;
    return *this;
}

Bookstore &Bookstore::displayBooks()
{
    for(int i = 0; i < MAX_BOOKS; i++)
    {
        cout << "Book " << i << endl;
        booklist[i].display();
        cout << endl;
    }
    return *this;
}

Bookstore &Bookstore::sellBook(int index)
{
    booklist[index].sell();
    return *this;
}

int main()
{
    Bookstore store;

    store.addBook(Book("1984", "George Orwell", 9.99))
        .addBook(Book("Animal Farm", "George Orwell", 7.99))
        .addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 14.99))
        .addBook(Book("A Brief History of Time", "Stephen Hawking", 15.99))
        .addBook(Book("Sapiens", "Yuval Noah Harari", 18.99));

    store.displayBooks()
        .sellBook(1)
        .sellBook(3);

    std::cout << "Total Books Sold: " << Book::totalSales << std::endl;
    return 0;
}
