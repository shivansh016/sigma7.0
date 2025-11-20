#include <iostream>
#include <cstring>
using namespace std;

int main (){
    
    char str1[] = "abc";
    char str2[] = "abc";
    char str3[] = "xyz";
    char str4[] = "x";

    cout << strcmp(str1,str2) << endl;
    cout << strcmp(str3,str1) << endl;
    cout << strcmp(str1, str4) << endl;

    return 0;

    
}