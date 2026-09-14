#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book()
    {
        issued = false;
    }
};

class Member
{
public:
    int id;
    string name;
};

Book books[100];
Member members[100];

int bookCount = 0;
int memberCount = 0;

void addBook()
{
    cout << "\nEnter Book ID: ";
    cin >> books[bookCount].id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[bookCount].title);

    cout << "Enter Author Name: ";
    getline(cin, books[bookCount].author);

    books[bookCount].issued = false;

    bookCount++;

    cout << "Book added successfully!\n";
}

void addMember()
{
    cout << "\nEnter Member ID: ";
    cin >> members[memberCount].id;

    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, members[memberCount].name);

    memberCount++;

    cout << "Member added successfully!\n";
}

void issueBook()
{
    int id;

    cout << "\nEnter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].issued)
            {
                cout << "Book is already issued.\n";
            }
            else
            {
                books[i].issued = true;
                cout << "Book issued successfully!\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook()
{
    int id;

    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (!books[i].issued)
            {
                cout << "Book was not issued.\n";
            }
            else
            {
                books[i].issued = false;
                cout << "Book returned successfully!\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void searchBook()
{
    int choice;
    string search;

    cout << "\n1. Search by Title";
    cout << "\n2. Search by Author";
    cout << "\nEnter choice: ";
    cin >> choice;

    cin.ignore();

    cout << "Enter search text: ";
    getline(cin, search);

    bool found = false;

    for (int i = 0; i < bookCount; i++)
    {
        if ((choice == 1 && books[i].title == search) ||
            (choice == 2 && books[i].author == search))
        {
            cout << "\nBook ID: " << books[i].id;
            cout << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author;

            if (books[i].issued)
                cout << "\nStatus: Issued\n";
            else
                cout << "\nStatus: Available\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "Book not found.\n";
    }
}

void displayBooks()
{
    if (bookCount == 0)
    {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n--- Library Books ---\n";

    for (int i = 0; i < bookCount; i++)
    {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;

        if (books[i].issued)
            cout << "\nStatus: Issued\n";
        else
            cout << "\nStatus: Available\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Search Book";
        cout << "\n6. Display All Books";
        cout << "\n7. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            addMember();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            searchBook();
            break;

        case 6:
            displayBooks();
            break;

        case 7:
            cout << "\nThank you for using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
