#include <iostream>
using namespace std;

struct student
{
	string name;
	int roll_no;
	char div;
	float marks;
};
int main()
{
	
	    cout<<"Name: Pranav Kure\n";
    cout<<"Div: c\n";
    cout<<"Roll No: 69\n\n";
   
	student s;
	cout<<"enter name:";
	cin>>s.name;
	cout<<"enter roll_no:";
	cin>>s.roll_no;
	cout<<"enter div:";
	cin>>s.div;
	cout<<"enter marks:";
	cin>>s.marks;
	
	cout<<endl;
	cout<<"name:" <<s.name <<endl;
	cout<<"roll_no:" <<s.roll_no <<endl;
	cout<<"div:" <<s.div <<endl;
	cout<<"marks:" <<s.marks <<endl;
	
	return 0;
	
}
/*
O/P:
Name: Pranav Kure
Div: B
Roll No: 19

enter name:pranav
enter roll_no:69
enter div:c
enter marks:95

name:prathmesh
roll_no:19
div:B
marks:95

*/


