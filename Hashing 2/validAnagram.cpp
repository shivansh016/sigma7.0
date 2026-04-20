#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool isAnagram(string s, string t);

int main(){
    string s = "care";
    string t = "race";
    cout << "care, race are anagram : " << isAnagram(s, t ) << endl; // 1 -> yes, 0->not ... output 1

    string p = "lipid";
    string q = "tulip";
    cout << "lipid, tulip are anagram :" << isAnagram(p, q); // output 0

    return 0;
}

bool isAnagram(string s, string t){
    if(s.size() != t.size()){
        return false;
    }

    // map for storing the char, freq of the string s

    unordered_map<char, int> m;

    for(int i=0; i<s.size(); i++){
        if(m.count(s[i])){ // if char exist then increase the freq.
            m[s[i]]++;
        }else{
            m[s[i]] = 1;// if char not exist then insert
        }
    }

    // traverse t
    for(int i=0; i<t.size(); i++){
        if(m.count(t[i])){
            m[t[i]]--; //if char exist then reduce the freq.
            if(m[t[i]] == 0){// if freq. became 0 erase the pair..
                m.erase(t[i]);
            }
        }else{
            return false;// if not exist return false
        }
    }

    return m.size() == 0; // if all the elements are deleted then return true.. otherwise false.

}

// Output:
// care, race are anagram : 1
// lipid, tulip are anagram :0