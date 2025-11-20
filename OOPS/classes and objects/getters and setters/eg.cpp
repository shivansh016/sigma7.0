#include<iostream>
#include<string>
using namespace std;


class student{
    
    string name;
    float cgpa;
    
    public:
     
    void getpercentage(){
        cout<< (cgpa*10) << endl;
    }

    //setters
    void setName(string nameVal){
        name = nameVal;
    }

    void setCgpa(float cgpaVal){
        cgpa = cgpaVal;
    }

    //getters

    string getName(){
        return name;
    }

    float getCgpa(){
        return cgpa;
    }

};

int main (){
    student s1;
    s1.setName("Shivansh");
    s1.setCgpa(8.5);


    cout << s1.getCgpa() << endl;
    cout << s1.getName() << endl;

    return 0;


}