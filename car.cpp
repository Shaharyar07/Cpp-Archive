#include <iostream>
#include <string.h>
using namespace std;

struct Stud{
	string driver_name;
	string car_name;
	string reg_no;
	int car_type;
	int km;
	Stud *next;
	Stud*prev;
	Stud*rides;
};
struct Stud2{
	int km1;
	int charges;
	string rider_name;
	Stud2 *r;
};
void register_car();
void display_registeredCars();
void display_rides();
void total_earning();
void new_ride();
void earning_car();
void earning_allCars();
void type2();
Stud *first = NULL;
Stud *last = NULL;
int main(){
	int k;
	int opt;
	do
	{
		cout<<"\n Enter 1 to Rigester ner car ";
		cout<<"\n Enter 2 to display detail of registered car";
		cout<<"\n Enter 3 to displat type 2 cars";
		cout<<"\n Enter 3 to Total earning from specific car";
		cout<<"\n Enter 4 to add new ride";
		cout<<"\n Enter 5 to display earning of all cars";
		cout<<"\n Enter 6 to display cars with ac";
		cin>>opt;
		switch(opt)
		{
			case 1: register_car();
			break;
			case 2: display_registeredCars();
			break;
			case 3: type2();
			break;
			case 4: new_ride();
			break;
			case 5: display_rides();
			break;
			case 6: earning_car();
			break;
			case 7: earning_allCars();
			break;
			default:
				cout<<"\n Enter valid option";
	
		}
	}while(opt!=0);
return 0;	
}
void register_car(){
	cout<<"\n Welcome to Car Registeration \n " ;
	Stud *curr = new Stud;
	curr->next = NULL;
	cout<<"\n Enter the driver's name : \n ";
	cin>>curr->driver_name;
	cout<<"\n Enter the car name \n ";
	cin>>curr->car_name;
	cout<<"\n Enter the Registeration Number : \n";
	cin>>curr->reg_no;
	cout<<"\n Enter the car type : press 1 for non AC press 2 for AC : \n";
	cin>>curr->car_type;
	cout<<"\n Enter the total KM driven by car : \n";
	cin>>curr->km;
	
	if( first == NULL){
		first = last = curr;
		curr->rides=Stud2;
	}
	else{
		last->next = curr;
		curr->prev=last;
		last = curr;
		last->rides=Stud2;
	}
	cout<<"car registered!!!. \n ";
	
}
void display_registeredCars(){
	stud *p=first;
	while(p!= NULL){
		cout<<p->driver_name<<" \n ";
		cout<<p->car_name<<" \n ";
		cout<<p->reg_no<<" \n ";
		cout<<p->car_type<<" \n ";
		cout<<p->km<<" \n ";
		p = p->next;
	}
}
void type2(){
	if (car_type==2){
		cout<"the car has AC \n ";
		display_registeredCars();
		
	}
	else
		cout<"the car does not have AC \n ";
	
}
void new_ride(){
	Stud2 *curr = new Stud2;
	curr->next = NULL;
	cout<<"\n Enter rider name : \n ";
	cin>>curr->rider_name;
	cout<<"\n Enter the total km \n ";
	cin>>curr->km1;
	cout<<"\n Enter the charges : \n";
	cin>>curr->charges;
	if( first == NULL){
		first = last = curr;
	}
	else{
	last->r=curr;
	last=curr;
}
	
	
}
void display_rides(){
	stud2 *p=first;
	while(p!= NULL){
		cout<<p->rider_name<<" \n ";
		cout<<p->km1<<" \n ";
		cout<<p->charges<<" \n ";
		p = p->next;
	}
	
}
void earning_car(){
	stud2 *p=first;
	while(p!= NULL){
		earning=charges*km1;
		p = p->next;
		
}
}
void earning_allCars(){
	
}