#include <stack>
#include <queue>
#include <string>
#include "stdlib.h"
#include <iostream>
using namespace std;

template <typename T>
T popq(queue<T> &myqueue)
{
	T temp = myqueue.front();
	myqueue.pop();

	return temp;
}

template <typename T>
T pops(stack<T> &mystack)
{
	T temp = mystack.top();
	mystack.pop();
	return temp;
}

int main()
{
	string str = "";
	queue<char> q1;
	stack<char> s1;
	bool flag = true;

	cout << "Please enter a word or phrase.\n";
	getline(cin, str);
	system("cls");
	for(int i = 0; i < str.length(); i++)
	{
		if(isalpha(str[i]))
		{
			if(islower(str[i]))
			{
				q1.push(str[i]);
				s1.push(str[i]);
			}
			else
			{
				q1.push(tolower(str[i]));
				s1.push(tolower(str[i]));
			}
		}
	}

	while(flag)
	{
		if(q1.empty() && s1.empty())
			break;
		else if(popq(q1) != pops(s1))
			flag = false;
		
	}
  cout<<"0. means FALSE! 1. means TRUE!"<<endl;
  cout<<"Output: " << flag<<endl; 
	if(flag)
		cout << "\"" <<str << "\"" << " is a palandrome!" << endl;
	else
		cout << "\"" << str << "\"" << " is not a palandrome...." << endl;
    

	return 0;
}