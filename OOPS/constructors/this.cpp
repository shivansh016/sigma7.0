// this pointer is used to refer to the current object
// it is an implicit parameter to all non-static member functions

#include<iostream>
#include<string>
using namespace std;

class car {
    string name;
    string color;
public:
    car(string name, string color) {
        cout << "constructor is called. object is created ... \n";
        this->name = name;
        this->color = color;}

    
    };