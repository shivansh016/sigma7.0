#include<iostream>
#include<cstring>
using namespace std;

bool Ispalindrome(char arr[], int n){
    int st = 0, end = n-1;
    while (st<end){
        if(arr[st++] != arr[end--]){
            cout << arr <<" Not a valid Palindrome" << endl;
            return false;
        }
        
    }
    
    cout << arr << " Valid Palindrome" << endl;
    return true;
}

int main (){
    char word[] = "RACECAR";
    char word2[] = "Apple";
    Ispalindrome(word, strlen(word));
    Ispalindrome(word2, strlen(word2));
    return 0;
}