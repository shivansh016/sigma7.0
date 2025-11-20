#include<iostream>
#include<cstring>
using namespace std;

int main(){
    // char word[40];
    // cout<< "input char array :" << endl; 
    // cin>>word; //problem with cin is that it ignores all the characters after the blank space eg:shivansh tiwari // will ignore tiwari

    // cout << "your word was : " << word << endl;
    // cout << "length : " << strlen(word) << endl;

    char arr[40];
    cout<< "input char array :" << endl; 
    cin.getline(arr,40); //will include space 

    cout << "your word was : " << arr << endl;
    cout << "length : " << strlen(arr) << endl;

    cout<<endl;

    cout<< "input char array(delimitter is '.') :" << endl; 
    cin.getline(arr,40,'.'); //will include space 

    cout << "your word was : " << arr << endl;
    cout << "length : " << strlen(arr) << endl;

    //individual character cout 
    cout<< "input char array :" << endl; 
    cin.getline(arr,40); //will include space 

    cout << "your word was : " << arr << endl;
    cout << "first character:" << arr[0] << endl;
    cout << "length : " << strlen(arr) << endl;

    return 0;
}