#include<iostream>
#include<string>
using namespace std;

class car {
    public:
    string name;
    string color;

    car(string name, string color) {
        cout << "constructor is called. object is created ... \n";
        this->name = name;
        this->color = color;
    }


    
   

};

int main (){
    car c1("maruti 800", "black");
    car c2(c1); // default copy constructor is called
    cout << c2.name << endl;
    cout << c2.color << endl;
    return 0;
}