#include<iostream>
#include<string>
using namespace std;


// m1: that uses the index method
// int main () {
//     string str = "apna college!";
//     for (int i=0; i<str.length(); i++){
//         cout << str[i] << "-" ;
//     }
//     cout<< endl;
//     return 0;
// }


//m2 : useful when we have to access only individual elements not indices
int main () {
    string str = "apna college!";
    for (char ch : str){ // remember the syntax
        cout << ch << "-" ;
    }
    cout<< endl;
    return 0;
}