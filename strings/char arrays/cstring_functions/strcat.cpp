#include <iostream>
#include <cstring>
using namespace std;

int main (){
    char str1[] = "abc";
    char str2[] = "xyz";
    strcat(str1, str2);
    cout<< str1 << endl; //abcxyz
    cout << str2 << endl; //xyz

    return 0;
}