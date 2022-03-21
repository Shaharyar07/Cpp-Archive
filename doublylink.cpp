#include <iostream>
#include <string.h>
using namespace std;
void student(int data);
void deletenode();
void display();
struct node
{
  int data;
  node *next;
  node *prev;
};
struct node *head, *newnode, *tail;
int data;
main()
{
  cout << "Hello!!!" << '\n';
  int opt, choice = 1;
  while (choice == 1)
  {
    cout << "1 to create node 2 to delete node and 0 to exit" << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
      cout << "Enter the data: ";
      cin >> data;
      createnode(data);
      break;
    }
    case 2:
    {
      deletenode();
      break;
    }
    case 0:
    {
      choice = 0;

    }
    }
  }

  display();
  return 0;
}
void createnode(int data)
{

  newnode = new node();
  newnode->data = data;
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
  cout << "Node created successfully... " << '\n';
}
void deletenode()
{
  struct node *temp;
  if (head == 0)
  {
    cout << "List is Empty";
  }
  else
  {
    temp = head;
    head = head->next;
    head->prev = 0;
    free(temp);
    cout << "Node Deleted successfully... " << '\n';
  }?
}

void display()
{
  struct node *show;
  show = head;
  while (show != 0)
  {
    cout << show->data << "\t";
    show = show->next;
  }
}
