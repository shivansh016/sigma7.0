#include<iostream>
#include<cstring>
using namespace std;

void toLower(char word[], int n){
    for(int i=0; i<n; i++){
        char ch = word[i];
        if(ch >= 'a' && ch <= 'z'){ //already lower
            continue;
        }
        else{ //when upper
            word[i] = ch-'A'+'a';
        }
    }
}

int main(){
    char word[]="ApPle";
    int size = strlen(word);
    toLower(word,size);
    cout << word << endl;
    return 0;
}