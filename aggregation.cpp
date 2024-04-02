#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(string t, string a)
    {
        title = t;
        author = a;
    }
};

class Library {
private:
    static const int Max_Books = 100;
    Book* books[Max_Books];
    int num_books;

public:
    Library()
    {
        num_books = 0;
   
    }

    void add_book(Book* book) {
        if (num_books < Max_Books) {
            books[num_books++] = book;
        }
        else {
            cout << "Library is full!" << endl;
        }
    }

    void remove_book(Book* book) {
        for (int i = 0; i < num_books; ++i) {
            if (books[i] == book) {
             
                books[i] = books[num_books - 1];
                num_books--;
                cout << "Book removed from the library." << endl;
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    void search_by_title(string title) {
        bool found = false;
        for (int i = 0; i < num_books; ++i) {
            if (books[i]->title == title) {
                cout << "Title: " << books[i]->title << ", Author: " << books[i]->author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the given title." << endl;
        }
    }

    void search_by_author(string author) {
        bool found = false;
        for (int i = 0; i < num_books; ++i) {
            if (books[i]->author == author) {
                cout << "Title: " << books[i]->title << ", Author: " << books[i]->author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "This Author has not written any book." << endl;
        }
    }
  
};

int main() {
    Library library;

    Book book1("Object Oriented Programming", "Tonny Gaddis");
    Book book2("C++ by Me", "Mr Abdullah");

    library.add_book(&book1);
    library.add_book(&book2);

    cout << "Books by title:" << endl;
    library.search_by_title("Object Oriented Programming");

    cout << "\nBooks by author:" << endl;
    library.search_by_author("Mr Abdullah");

    cout << "\nRemoving a book..." << endl;
    library.remove_book(&book1);

    return 0;
}
