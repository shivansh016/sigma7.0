#include<iostream>
#include<string>
using namespace std;

int main () {
    string strg = "helloworld!";
    string str = "I love c++ and java";
    cout << strg.length() << endl;
    cout << strg[5] << endl;
    cout << strg.at(5) << endl; //line 8 and 9 mean the same 

    cout << strg.substr(1,5) << endl; //ellow
    cout << str.find("c++") << endl; // 7
    cout << str.find("python") << endl; //-1 but here it shows its equivalent in unsigned char to get -1 declare it inside a integer 
    
    int idx = str.find("phone") ;
    cout << idx << endl; // -1 now

    string str1 = "I love coding in c++ & c++. I don't like c++";
    cout << str1.find("c++") << endl; //17
    cout << str1.find("c++" , 20) << endl; //23

    return 0;
}