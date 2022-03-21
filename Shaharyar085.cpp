#include <iostream>
#include <string.h>

using namespace std;
void createnodeatStart(int age, int sallery, char gender);
void createnodeatEnd(int age, int sallery, char gender);

void display();
struct employee
{
    int age; // data
    int sallery;
    char gender;
    employee *link; // pointer to next
};

employee *head = NULL, *tail = NULL, *temp = NULL;

int main()
{
    int i, age, sallery;
    char gender, user;

    for (i = 1; i <= 4; i++)
    {
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sallery: ";
        cin >> sallery;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Where to add?";
        cin >> user;
        if (user == 's')
        {
            createnodeatStart(age, sallery, gender);
        }
        else
        {
            createnodeatEnd(age, sallery, gender);
        }
    }

    display();
    return 0;
}
void createnodeatEnd(int age, int sallery, char gender)
{
    temp = new employee();

    temp->age = age;
    temp->sallery = sallery;
    temp->gender = gender;

    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->link = temp;
        tail = temp;
    }
}

void createnodeatStart(int age, int sallery, char gender)
{
    temp = new employee();

    temp->age = age;
    temp->sallery = sallery;
    temp->gender = gender;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
}

void display()
{

    temp = head;
    while (temp != NULL)
    {
        cout << temp->age << "\t";
        cout << temp->sallery << "\t";
        cout << temp->gender << "\n";
        temp = temp->link;
    }
}
