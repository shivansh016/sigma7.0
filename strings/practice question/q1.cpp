#include<iostream>
#include<string>
using namespace std;

int lowerVowels ( string str ){
    int count = 0;
    for(int i=0; i<str.length(); i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ){

            count = count + 1;
        }
    }
  cout << "number of lowercase vowels in Entered string are : "<< count;
  return count;


}


int main (){
    string str ;
    cout << "Enter a string : ";
    getline(cin, str);

    cout << "entered string is : ";
    cout << str << endl;
    lowerVowels(str);

    return 0;



}