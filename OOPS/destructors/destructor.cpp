#include<iostream>
#include<string>
using namespace std;

class car{
    public:
    string name;
    string color;
    int *mileage;

    car(string name, string color) {
        
        this->name = name;
        this->color = color;
        mileage = new int; // dynamically allocate memory
        *mileage = 12; // assign value
    }

    // copy constructor
    // performs deep copy
    car (car &original) {   
        cout << "deep copy constructor copying original to new... \n";
        name = original.name;
        color = original.color;
        mileage = new int; // allocate new memory
        *mileage = *original.mileage; // copy value
    }

   ~car(){
        cout << "deleting object.. \n" ;
   }

};

int main (){
    car c1("maruti 800", "black");
    car c2(c1); // copy constructor is called
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << "c1 mileage: " << *c1.mileage << endl;
    cout << "c2 mileage: " << *c2.mileage << endl;

    // modifying c2 mileage
    *(c2.mileage) = 10;
    cout << "after modifying c2 mileage: \n";
    cout << "c1 mileage: " << *c1.mileage << endl; // does not reflect change due to deep copy
    cout << "c2 mileage: " << *c2.mileage << endl;

    return 0;
}