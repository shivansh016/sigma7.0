#include<iostream>
#include<string> // to use string class
using namespace std;

int main ( ){
    string str = "Hello";
    cout << str << endl;
    str = "yellow"; // here we changed value of string in runtime which is not possible in the char arrays ........ assigned a string literal to the string  (not possible in the char arrays)
    
    cout << str << endl;
    return 0;
}