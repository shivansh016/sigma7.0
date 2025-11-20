#include <iostream>
#include<cstring>
using namespace std;

int main (){
    

    //Method 1: without size 

    char work[] = "code";
    cout << work << endl; //code
    
    //Method 2: giving size 

    char work2[5] = "code";
    cout << work2 << endl; //code

    //Method 3:without size, giving individual elements

    char work3[] = {'c','o','d','e','\0'};
    cout << work3 << endl; //code

    //Method 4: giving size and individual elements
    char work4[5] = {'c','o','d','e','\0'};
    cout << work4 << endl; //code


    //strlen() : function used to know the string length , or character array length, doesn't counts the Null character
    char arr[50] = {'c','o','d','e','\0'};
    cout << strlen(arr) <<endl;

    return 0;
}