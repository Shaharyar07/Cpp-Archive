#include <iostream>
#include "string.h"
using namespace std;
void createnodeatStart(int age,int sallery,char gender);
void createnodeatEnd(int age,int sallery,char gender);
void display();
void deleteatBegining();
void deleteatEnd();

struct employee {
  int age;
  int sallery;
  char gender;
  employee* next;

};
employee *head = NULL,*tail = NULL,*temp = NULL;

int main() {
int count, i,age,sallery, choice;
char gender,user ;
cout<<" How many times Do you want to proceed?"<<"\n";
cin>>count;
for  (i = 0; i < count; i++) {
  cout<<"Do you want to create(c) or delete(d) a node?: ";
  cin>>user;
  if (user=='c') {
    cout<<"Enter 1 to createnodeatStart, 2 to createnodeatEnd:"<<endl;
    cin>>choice;
  }
  else if (user=='d') {
    cout<<"Enter 3 to deleteatBegining and 4 to deleteatEnd: ";
    cin>>choice;
  }
  switch (choice) {
    case 1:
          {
            cout<<"Enter Age: ";
            cin>>age;
            cout<<"Enterr your Sallery: ";
            cin>>sallery;
            cout<<"Gender: ";
            cin>>gender;
          createnodeatStart(age, sallery,gender);
          break;
        }
    case 2:
    {
      cout<<"Enter Age: ";
      cin>>age;
      cout<<"Enterr your Sallery: ";
      cin>>sallery;
      cout<<"Gender: ";
      cin>>gender;
      createnodeatEnd(age,sallery,gender);
      break;
    }
    case 3:{
      deleteatBegining();
      break;
    }
    case 4:{
      deleteatEnd();
      break;
    }
    default:
          break;
  }
}
display();
return 0;
}
void createnodeatStart(int age,int sallery,char gender) {
  temp = new employee();
  temp->age = age;
  temp->sallery = sallery;
  temp->gender = gender;
  temp->next = NULL;
  if (head==NULL) {
    head = temp;
    tail = temp;
    temp->next = NULL;

  }
  else{
    temp->next = head;
    head = temp;
  }

}
void createnodeatEnd(int age,int sallery,char gender) {
  temp = new employee();
  temp->age = age;
  temp->sallery = sallery;
  temp->gender = gender;
  temp->next = NULL;
  if (head==NULL) {
    head = temp;
    tail = temp;
    temp->next = NULL;

  }
  else{
    tail->next = temp;
    tail = temp;
  }

}

void deleteatBegining() {
  struct employee *temp;
  temp = head;
  head = head->next;
  free(temp);
}
void deleteatEnd(){
  struct  employee *prevnode;
  temp=head;
  while (temp->next!=0) {
    prevnode=temp;
    temp= temp->next;
  }
    if (temp==head) {
      tail=0;
    }
    else{
      prevnode=temp;
      prevnode->next=0;
    }
    free(prevnode);



}
void display()
{

	temp = head;
	while(temp!=NULL)
	{
	    cout<<temp->age<<"\t";
		cout<<temp->sallery<<"\t";
		cout<<temp->gender<<"\n" ;
	    temp=temp->next;
	}
}
