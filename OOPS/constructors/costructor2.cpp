#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string color;
    public:
     car(string nameVal, string colorVal){
        cout << "constructor is called. object is created ... \n";
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
    car c1("maruti 800", "white");
    cout << "car name is: " << c1.getname() << endl;;
    return 0;
}