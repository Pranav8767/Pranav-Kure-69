
// C++ program to show unary operator overloading
#include <iostream>
using namespace std;

class Distance {
public:
    int feet, inch;
    // Constructor to initialize the object's value
    Distance(int ft, int i) {
        this->feet = ft;
        this->inch = i;
    }

    // Overloading(-) operator to perform decrement operation of Distance object
    void operator--() {
        feet--;
        inch--;
        cout << "Feet & Inches(Decrement): " << feet << "'" << inch;
    }
};

// Driver Code
int main() {
        cout<<"Name:  Pranav Kure \n";
    cout<<"Div: c\n";
    cout<<"Roll No: 69\n\n";
    Distance d1(8, 9);
    // Use (-) unary operator by single operand
    --d1;
    return 0;
}

/*
Output:

Name: Pranav Kure 
Div: c
Roll No: 69

Feet & Inches(Decrement): 7'8
*/