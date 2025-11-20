#include <iostream>
#include <cstring>
using namespace std;

int main (){
    
    
    
    char arr1[100];
//  arr1 = "Hello world";// will show error as we can't pass literals to the character arrays ,,,  we have to make it a character array 
    \
    strcpy(arr1, "Hello world");// converts Hello world to char arr/string and then copies it to arr1
    cout << arr1 << endl;
    char arr2[] = "Apna college GLBITM";
    strcpy(arr1, arr2);
    cout << arr1 << endl;
    return 0;
}