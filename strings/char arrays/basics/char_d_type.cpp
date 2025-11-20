#include<iostream>
using namespace std; 

int main () {
    // declaration

    char ch1 = 'a';
    char ch2 = 'Z';
    char ch3 = '%';
    char ch4 = '9';
    char ch5 = '\t'; // tabspace character

    // to get ASCII values

    cout << int(ch1) << endl; //97
    cout << int(ch2) << endl;  //90
    cout << int(ch3) << endl;  //37
    cout << int(ch4) << endl;  //57
    cout << int(ch5) << endl;  //9

cout << endl;

    cout << (int) ch1 << endl; //97
    cout << (int) ch2 << endl;  //90
    cout << (int) ch3 << endl;  //37
    cout << (int) ch4 << endl;  //57
    cout << (int) ch5 << endl;  //9

cout << endl;
    
    // to get position of any alphabet

    char ch = 'f';
    int pos = ch - 'a';
    cout << pos << endl; //5

cout << endl;

    char char1 = 'F';
    int pos1 = char1 - 'A';
    cout << pos << endl; //5

    

    return 0 ;

}