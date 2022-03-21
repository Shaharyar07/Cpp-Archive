// C++ code to implement age Queue
// using Linked List
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	string name;
	int age;

	struct node* next;

} Node;

Node* newNode(string name, int age)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->name = name;
	temp->age = age;
	temp->next = NULL;

	return temp;
}

string peek(Node** head)
{
	return (*head)->name;
}

void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

void push(Node** head, string name, int age)
{
	Node* start = (*head);

	Node* temp = newNode(name, age);

	if ((*head)->age > age)
	{
		
		temp->next = *head;
		(*head) = temp;
	}
	else
	{
		
		while (start->next != NULL &&
			start->next->age < age)
		{
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}
}

int isEmpty(Node** head)
{
	return (*head) == NULL;
}

int main()
{
	Node* pq = newNode("sarmad", 19);
	push(&pq, "Umair", 18);
	push(&pq, "Huzaifa", 20);
	push(&pq, "Shaharyar", 22);

	while (!isEmpty(&pq))
	{
		cout << " " << peek(&pq)<<endl;
		pop(&pq);
	}
	return 0;
}

