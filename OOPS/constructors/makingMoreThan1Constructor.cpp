#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string color;
    public:

     car(){
        cout << "constructor without parameters ...\n";
     }


     car(string nameVal, string colorVal){
        cout << "constructor with parameters.... \n";
        name = nameVal;
        color = colorVal;
     }

     void start(){
        cout << "car started \n";
     }
     void stop(){
        cout << "car stopped \n";
     }

     // getter functions 

     string getname(){
        return name;
     }
     string getcolor(){
        return color;
     }
};

int main (){
    car c0;
    car c1("maruti 800", "white");
    car c2("swift", "black"); // compiler automatically calls parameterized constructor
    return 0;
}