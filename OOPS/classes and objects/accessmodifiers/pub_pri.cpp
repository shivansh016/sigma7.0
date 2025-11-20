#include<iostream>
#include<string>
using namespace std;

class user {
    int id ;
    string password;
public:
    string username;
    string bio;

    void deactivate(){
        cout << "deleting account \n" ;

    }

    void editbio(string newBio){
        bio = newBio;
    }
};

class student{
    private:
      string name;
    public:
      float cgpa;
    void getpercentage(){
        cout<< (cgpa*10) << endl;
    }
};

int main (){
    student s1;
    s1.cgpa = 8.5;
    s1.getpercentage();
    cout << s1.cgpa << endl;
    return 0;
}