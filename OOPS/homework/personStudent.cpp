#include<iostream>
#include<string>
using namespace std;

class Person{
    public :
     string name;
     int age;
};

class Student : public Person{
    protected : 
     string studentID;

     public : 

     Student (string name, int age, string id){
        this->name = name;
        this->age = age;
        this->studentID = id;
     }

     void displayStudentInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID <<endl;
     }
        
};

int main (){
   
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();
    return 0;
}