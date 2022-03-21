#include <iostream>
#include <string.h>

using namespace std;
void createnode;
void segregateEvenOdd(struct Node *Head);
Display();
Struct Node{
  int data;
  Node *next;
}
int main()
{ 
  int data,choice=1;
  while(choice==1)
  for(int i=0,i<5,i++){
    cout<<"Enter Data: ";
    cin>>data;
    createnode(data);
  }
  display();
  
  choice=0  
}

Node *head = NULL, *tail = NULL, *temp = NULL;
void createnode(int data)
{
    temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void segregateEvenOdd(struct Node *Head)
{
  
    Node *evenStart = NULL;
      
    Node *evenEnd = NULL;

    Node *oddStart = NULL;
      
    Node *oddEnd = NULL;
      
  
    Node *currNode = *Head;
      
    while(currNode != NULL){
        int val = currNode -> data;
          
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }
              
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        } 
          
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
        
        currNode = currNode -> next;    
    }
  
    if(oddStart == NULL || evenStart == NULL){
        return;
    }
      
    // Add odd list after even list.     
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
  
    *Head = evenStart;
}
