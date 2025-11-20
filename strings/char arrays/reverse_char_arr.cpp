#include <iostream>
#include <cstring>
using namespace std;

void reverse(char arr[], int n){
    int st=0, end=n-1;
    while(st<end){
        swap(arr[st++],arr[end--]);

        // can also write
        // swap(arr[st],arr[end]);
        // st++;
        // end--;
    }
}

int main (){
    char words[] = "code is this";
    reverse(words, strlen(words));
    cout << "revere = " << words << endl;
    return 0;
}