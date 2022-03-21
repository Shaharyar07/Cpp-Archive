#include<iostream>
 using namespace std;
/* functions for input, scan, push and pop
------------------------------------------*/ 
 void input();   //  function that get input(infix expression from user
 void convert();   //   function that convert infix expression to postfix expression
 void push();   //   function that push operation onto stack
 void pop();   //    function that remove item from stack
 void output(char out);
//------------------------------------------


/* Data : 
------------------------------------------*/
char infix_expression[100];   //  hold the infix expression
char stack[20]; // stack to hold operations
char ch;        //  hold the individual character from infix expression
char poped_item;
int top = -1;   //  variable to point the top of the stack
//------------------------------------------ 


int main()
{
	
	input();
	convert();
	
}

void input()
{
	cout<<"Enter valid infix expression without space"<<endl;
	cin>>infix_expression;
}

void convert()
{
	for(int i= 0; infix_expression[i]!='\0';i++)
	 {
	 	ch =infix_expression[i];
	 	if(ch=='('||ch=='*'||ch=='/'||ch=='+'||ch=='-'||ch==')')
	 	{
	 	   if(ch=='(')
			  push();
		   else if(stack[top]=='(')
			  push();
		   else if(ch==')')
			  pop();
		   else if((stack[top]=='+'||stack[top]=='-')&&(ch=='*'||ch=='/'))
			   push();
		   else if(top==-1)
			   push();
			else
			   {
			   	pop();
			   	push();
			   }  	
		}
		else
		  output(ch);   //cout<<ch<<" ";
	 }
	 pop();  
}

// function to push operators into stack

void push()
{
	top++;
	stack[top]= ch;
}

// function to push operators into stack
void pop()
{
	while(top!= -1)
	{
		if(ch==')')
		{
			poped_item =stack[top];
			output(poped_item);
			//cout<<stack[top]<<" ";
			top--;
			if(stack[top]=='(')
			{
				top--;
				break;
			}
			
		}
		else
			{
				poped_item =stack[top];
			    output(poped_item);
				//cout<<stack[top]<<" ";
				top--;
				if(stack[top]=='(')
				  break;
			}
	}
}

void output(char out)
{
	cout<<out<<" ";
}
