#include<bits/stdc++.h>
using namespace std;
  
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};
  

void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
    (*head_ref)    = new_node;
}
  
// Function to check if list is palindrome or not
bool isPalindrome(struct Node *left)
{
    if (left == NULL)
       return true;
  
    // Find right most node
    struct Node *right = left;
    while (right->next != NULL)
        right = right->next;
  
    while (left != right)
    {
        if (left->data != right->data)
            return false;
  
        left = left->next;
        right = right->prev;
    }
  
    return true;
}
  

int main()
{
    struct Node* head = NULL;
    push(&head, 's');
    push(&head, 'o');
    push(&head, 'l');
    push(&head, 'o');
    push(&head, 's');
  
    if (isPalindrome(head))
        printf("It is Palindrome");
    else
        printf("It is not a Palindrome");
  
    return 0;
}