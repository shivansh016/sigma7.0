//usage of this pointer to resolve naming conflict
// when local variable and instance variable have same name
// the syntax is: this->variable_name
// or you can also use (*this).variable_name
#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string color;
    public:
     car(string name, string color){
        cout << "constructor is called. object is created ... \n";
        this->name = name;
        this->color = color;
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