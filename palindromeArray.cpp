
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
#define MAX 50

class Stack  {
private:
  char data[MAX],str[MAX];
  int top,length,count;

  void pushData(char);
  char popData();

public:
  Stack() {
    top=-1;
    length=0;
    count=0;
  }
  void getString();
  void checkPalindrome();
  
};

int main()  {
  Stack obj;
  obj.getString();
  obj.checkPalindrome();
  return 0;
}

void Stack::getString() {
  cout<<"\n Enter a String: ";
  cin.getline(str,MAX);

  length=strlen(str);
}



void Stack::checkPalindrome() {
  for(int i=0; i<length; i++)
    pushData(str[i]);

  for(int i=0; i<length; i++) {
    if(str[i]==popData())
      count++;
  }

  if(count==length) {
    cout<<"\n Entered string is a Palindrome. \n";
  }
  else  cout<<"\n Entered string is not a Palindrome. \n";
}


void Stack::pushData(char temp) {

  if(top==MAX-1)  {
    cout<<"\n Stack Overflow!!!";
    return;
  }

  top++;
  data[top]=temp;

}

char Stack::popData() {
  if(top==-1)  {
    cout<<"\n Stack Underflow!!!";
    char ch='\n';
    return ch;
  }
  char temp=data[top];
  top--;
  return temp;
}