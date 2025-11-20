#include<iostream>
using namespace std;

class student {
    // properties
    string name;
    float cgpa;
    
    // functions
    void getPercentage(){
        cout << (cgpa * 10) << "% \n" << endl;
    }
};

int main (){
    student s1; // object 
    cout << sizeof(s1) << endl;
    return 0;
}