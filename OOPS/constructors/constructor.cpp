#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string color;
    public:
     car(){
        cout << "constructor is called. object is created ... \n";
     }

     void start(){
        cout << "car started \n";
     }
     void stop(){
        cout << "car stopped \n";
     }
};

int main (){
    car c1;
    return 0;
}