#include <iostream>
#include "string.h"
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int  data;		// data
    node * next;		// pointer to next
};

node * createnode(int data);
void display();
int size();
void remove(int index);
void duplicate();
void reverse();
void removeDuplicates();
bool isPalin();
void swapKth(int k);
node* reversesize(node* head, int k);



node * head=NULL,* tail=NULL, * temp = NULL;
int main() {
    int i,k, data, index, counter;
    int choice = 1;
    while (choice == 1) {
        cout << "1. to createnode," <<'\t'<<" 2. to get size of list," << endl <<
            "3. to remove node at given index from List," << endl <<
            "4. to display," <<'\t'<<" 5. to display copy," <<'\t'<<" 6. to reverse  " << endl <<
            "7 to delete duplicate items," <<'\t'<<" 8 to check palindrome, 9 to swap" <<endl<<
            "10. to reverse some part of linklist..... and 0. to exit: ";
        std:: cout << '\n'<<"  -------------------------------------  " << '\n';
        std:: cout << "Enter your choice: " << '\n';
        cin >> i;
        switch (i) {
            case 1:
                {
                    cout << "Enter data: ";
                    cin >> data;
                    createnode(data);
                    break;
                }
            case 2:
                {
                    size();
                    break;
                }
            case 3:
                {
                    cout << "Enter the index you want to delete the node: ";
                    cin >> index;
                    remove(index);

                    break;
                }
            case 4:
                {
                    display();
                    break;
                }
            case 5:
                {
                    duplicate();
                    break;

                }
            case 6:
                {
                    reverse();
                    break;
                }
            case 7:
                {
                    removeDuplicates();
                    break;
                }
						case 8:
								{
									 isPalin();
									break;
								}
						case 9:
						    {
									std::cout << "Enter the index of the node you want to swap: " << '\n';
									cin>>k;
									swapKth(k);
									break;
						    }
                case 10:
                {
                  std::cout << "Enter the size of the list you want to swap: " << '\n';
                  cin>>k;
                  head  =reversesize(head,k);
                  display();
                }

            case 0:
                {
                    choice = 0;
                    break;
                }
        }
    }
    return 0;
}

node * createnode(int data)
{
    temp = new node();
    temp -> data = data;
    temp -> next=NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        temp -> next = head;
        head = temp;
    }
    return head;
}

void display()
{

    temp = head;
    while (temp != NULL) {
        cout << "Display: " << temp -> data << '\n';
        temp = temp -> next;
    }

}

int size()
{
    int counter = 0;
    temp = head;
    while (temp != NULL) {
        counter += 1;
        temp = temp -> next;
    }
    cout << endl << "Length is: " << counter << endl;
    return counter;
}

void remove(int index){
    struct node * nextnode;
    int i = 1;
    temp = head;
    if (index > size()) {
        cout << "Index out of bound!!!" << '\n';
    }
    else if (head -> next == NULL) {
        cout << "Sorry list cannot be empty!!!(one node only in Linked list....)" << '\n';
    }
    while (i < index - 1) {
        temp = temp -> next;
        i++;
    }
    nextnode = temp -> next;
    temp -> next = nextnode -> next;
    free(nextnode);
}

void duplicate() {
    node * temp;
    node * current = head;  //holds the current node
    node * copy = new node;
    copy -> next = NULL;
    std:: cout << "Duplicate: " << '\n';
    while (current != NULL) {
        (copy -> data) = (current -> data);
        (copy -> next) = (current -> next);
        cout << copy -> data << '\n';
        copy = copy -> next;
        current = current -> next;
    }
}

void reverse(){
    struct node * prevnode, * currentnode, * nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    std:: cout << "Reverse list: " << '\n';
    while (nextnode != 0) {
        nextnode = nextnode -> next;
        currentnode -> next=prevnode;

        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
    display();
}
void removeDuplicates()
{
    struct node * currentnode, * nextnode, * dup;
    currentnode = head;
    while (currentnode != NULL && currentnode -> next != NULL) {
        nextnode = currentnode;
        while (nextnode -> next != NULL) {
            /* If duplicate then delete it */
            if (currentnode -> data == nextnode -> next -> data) {
                dup = nextnode -> next;
                nextnode -> next = nextnode -> next -> next;
                delete (dup);
            }
            else
                nextnode = nextnode -> next;
        }
        currentnode = currentnode -> next;
    }
    temp = currentnode;
    display();
}
bool isPalin(){
    node * slow= head;
    stack < int > s;
    while (slow != NULL) {
        s.push(slow -> data);
        slow = slow -> next;
    }
    while (head != NULL) {
        int i = s.top();
				s.pop();
        if (head -> data != i) {
					std::cout << "Not palindrome" << '\n';
            return false;
        }
        head = head -> next;
    }
		std::cout << "List is palindrome" << '\n';
    return true;
}
void swapKth(int k)
{
    int n = size();
    if (n < k)
        return;
    if (2 * k - 1 == n)
        return;
    node* x = head;
    node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    node* y = head;
    node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    if (x_prev)
        x_prev->next = y;

    if (y_prev)
        y_prev->next = x;

    node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1)
        head = y;
    if (k == n)
        head = x;
		display();
}
node* reversesize(node* head, int k)
{

    if (!head)
        return NULL;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        head->next = reversesize(next, k);

    return prev;
}
