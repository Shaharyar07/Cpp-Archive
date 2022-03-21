#include <iostream>
#include <string.h>

using namespace std;
void regnewstudent(string StudentName, int regNum);
void displayStudent();
void addNewBook(string bookname, int Noofbooks, int booktype);
void displayBook();

struct student
{
    string StudentName;
    int regNum;
    student *prev;
    student *next;
};
struct book
{
    string bookName;
    int bookType;
    int numOfBooks;
    book *prev;
    book *next;
};
struct student *head, *newnode, *tail;
struct book *Head, *Tail;
string Studentname, bookname;
int noofbooks, regNum, booktype;
main()
{

    cout << "Hello!!!" << '\n';
    int opt, choice = 1;
    while (choice == 1)
    {
        cout << "1 to create newStudent 2 to displaystudent " << endl;
        cout << "3 to add new books 4 to display books and 0 to exit: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the name of student: ";
            cin >> Studentname;
            cout << "Enter the Reg Num: ";
            cin >> regNum;
            regnewstudent(Studentname, regNum);
            break;
        }
        case 2:
        {
            displayStudent();
            break;
        }
        case 3:
        {
            cout << "Enter the name of book: " << endl;
            cin >> bookname;
            cout << "Enter the numOfBooks: " << endl;
            cin >> noofbooks;
            cout << "Enter the bookType: ";
            cin >> booktype;
            addNewBook(bookname, noofbooks, booktype);

            break;
        }
        case 4:
        {
            displayBook();
            break;
        }

        case 0:
        {
            choice = 0;
        }
        }
    }

    return 0;
}
void regnewstudent(string Studentname, int regNum)
{
    newnode = new student();
    newnode->StudentName = Studentname;
    newnode->regNum = regNum;
    newnode->next = 0;
    newnode->prev = 0;
    if (head == 0)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail->prev = tail;
        tail = newnode;
    }
}
void addNewBook(string bookname, int Noofbooks, int booktype)
{
    book *newbook;
    newbook = new book();
    newbook->bookName = bookname;
    newbook->numOfBooks = noofbooks;
    newbook->next = 0;
    newbook->prev = 0;
    if (Head == 0)
    {
        Head = Tail = newbook;
    }
    else
    {
        Tail->next = newbook;
        Tail->prev = Tail;
        Tail = newbook;
    }
}
void displayStudent()
{
    struct student *show;
    show = head;
    while (show != 0)
    {
        cout << show->StudentName << "\t";
        cout << show->regNum << endl;
        show = show->next;
    }
}
void displayBook()
{
    struct book *showbook;
    showbook = Head;
    while (showbook != 0)
    {
        cout << showbook->bookName << "\t";
        cout << showbook->bookType << "\t";
        cout << showbook->numOfBooks << endl;
        showbook = showbook->next;
    }
}
