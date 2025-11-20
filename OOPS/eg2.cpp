#include<iostream>
using namespace std;

class user {
    int id ;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout << "deleting account \n" ;

    }

    void editbio(string newBio){
        bio = newBio;
    }
};