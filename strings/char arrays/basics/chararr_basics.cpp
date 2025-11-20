#include<iostream>
using namespace std;

int main(){
    char arr[5] = {'a','b','c','d','\0'}; //char array
    char arr1[5] = {'c','o','d','e','\0'};
    cout << arr << endl; // abcd return hoga as it is now an string since terminated by null character
    cout << arr1 << endl; // code

// NOTE: here arr is not a pointer anymore as it has become string, it is returning all values by combining in form of a string
    

"hello world"; // string literals, not required to be terminated explicitly by null character 
"a"; //string literals
"apna college"; //string literals

    return 0;
}