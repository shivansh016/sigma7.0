#include <iostream>
#include <cstring>
using namespace std;

int main (){
    char str1[100] = "abc";
    char str2[29] = {'a','b','d','g','\0'};
    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;

    return 0;
}