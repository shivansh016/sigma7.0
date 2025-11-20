#include<iostream>
#include<string>
using namespace std;

// int main (){
//     string str;
//     cout<< "enter string:" << endl;
//     getline(cin, str);  // without delimitter
//     cout << str << endl;
//     return 0;
// }


// using delimitter inside getline function

// int main (){
//     string str;
//     cout<< "enter string:" << endl;
//     getline(cin, str, '$'); //used delimitter $ 
//     cout << str << endl;
//     return 0;
// }

// accessing individual elements

int main (){
    string str;
    cout<< "enter string:" << endl;
    getline(cin, str, '$'); //used delimitter $ 
    cout << str[0] << endl;
    cout << str[1] << endl;
    cout << str[2] << endl;
    cout << str[3] << endl;

    cout << str << endl; // whole string
    return 0;
}