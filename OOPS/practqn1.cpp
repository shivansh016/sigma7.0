#include<iostream>
#include<string>
using namespace std;

class user {
    int id ;
    string password;

    public:
       string username;

       user(int id){
            this->id = id;
       }
    // setters 
       void setpassword(string password){
            this->password = password;
       }

    // getters

       string getpassword(){
            return password;
       }

    };

int main (){
    user u1(101);
    u1.username = "shivansh_tiwari";
    u1.setpassword("vscode123");
    
    cout << "password is: " << u1.getpassword() << endl;
    cout << "username is :" << u1.username << endl;
    return 0;

}