#include<iostream>
#include<cstring>
using namespace std;

void toUpper(char arr[], int n){
    for(int i=0; i<n; i++){
        char ch = arr[i];
        if(ch >= 'A' && ch <= 'Z'){
            continue;
        }
        else{
            arr[i] = ch-'a'+'A';
        }
    }
}

int main(){
    // char sentence[50];
    // cout << "Enter a character array : ";
    // cin.getline(sentence,50);
    // cout << "your char array :" << sentence << endl;;
    // int size = strlen(sentence);
    // toUpper(sentence,size);

    // cout << "after converting to upper case:" << sentence << endl;

    //commented out as it was only converting the first letter to capital

    char word[]="ApPle";
    int size = strlen(word);
    toUpper(word,size);
    cout << word << endl;
    // you can change the data of array to get any other word/string/char arr in capital  
    return 0;
}