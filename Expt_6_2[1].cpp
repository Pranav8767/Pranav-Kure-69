//Expt_6_2
// C++ program to implement Hierarchical Inheritance

#include <iostream>
using namespace std;

// base class
class Vehicle {
    public:
        Vehicle() { cout << "This is a Vehicle\n"; 
        }
};

// first subclass
class Car : public Vehicle {
    public:
        Car() { cout << "This Vehicle is Car\n";
        }
};

// second subclass
class Bus : public Vehicle {
    public:
        Bus() { cout << "This Vehicle is Bus\n";
        }
};

// main function
int main()
{
    cout<<"Name: Pranav Kure\n";
    cout<<"Div: c\n";
    cout<<"Roll No: 69\n\n";
    // Creating object of subclass will
    // invoke the constructor of base class.
    Car obj1;
    Bus obj2;
    return 0;
}
/*
Output:
Name:  Pranav Kure Div: c
Roll No: 69

This is a Vehicle
This Vehicle is Car
This is a Vehicle
This Vehicle is Bus
*/