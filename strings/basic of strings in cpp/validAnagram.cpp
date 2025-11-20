#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout<< "Not anagram\n"; //jab length hi same na ho
        return false; 
    }

    int count[26] ={0};

    for (int i = 0; i<str1.length(); i++){
        // int idx = str1[i]-'a';
        // count[idx]++;
        count[str1[i]-'a']++; //no need to make another variable index.... similarly in other loops as well
    }

    for(int i = 0; i<str2.length(); i++){
        int idx= str2[i] - 'a';
        if(count[idx] == 0){
            cout << "not valid anagrams\n";
            return false; //jab str2 me koi elements jyada baar aaye
        }
        count[idx]--;
    }
    cout << "valid anagram\n";
    return true;

}

int main (){
    string str1= "anagram";
    string str2= "nagaram";
    string str3 = "art";
    string str4 = "cat";
    isAnagram(str1, str2);
    isAnagram(str3, str4);

    return 0;
}