#include <iostream>
#include <string.h>
using namespace std;

void createnode(int age,int sallery , char gender);
void display();

struct employee
{
	int     	age;		// data
	int			sallery;
	char 		gender;
	employee*	link;		// pointer to next
};

employee *head=NULL,*tail=NULL, *temp = NULL;

int main() {
	int i,age,sallery;
	char gender;

	for(i=1;i<=4;i++)
	{
		cout<<"Enter age: ";
	  	cin>>age;
	  	cout<<"Enter sallery: ";
	  	cin>>sallery;
	  	cout<<"Enter gender: ";

		cin>>gender;

		createnode(age,sallery,gender);
   	}

	display();
	return 0;
}

void createnode(int age, int sallery, char gender)
{
    temp=new employee();

    temp->age = age;
    temp->sallery = sallery;
    temp->gender= gender;

    temp->link=NULL;

	if(head==NULL)
    {
	    head=temp;
	    tail=temp;
	    temp=NULL;
    }
  	else
  	{
    	tail->link=temp;
     	tail=temp;
 	}
}

void display()
{

	temp = head;
	while(temp!=NULL)
	{
	    cout<<temp->age<<"\t";
		cout<<temp->sallery<<"\t";
		cout<<temp->gender<<"\n" ;
	    temp=temp->link;
	}
}
