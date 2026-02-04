#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> m;

    m[101] = "rahul";//insertion
    m[110] = "raj";
    m[131] = "rahul";

    m[101] = "rajat" ; // will change the value at key 101 to rajat

    cout << m[101] << endl;
    cout << m[110] << endl;
    cout << m[131] << endl;
    
    cout <<m.count(101) << endl; //1 as key exist
    cout <<m.count(150) << endl; //0 as key doesn't exist

    for(auto it: m){ //using loop on map
        cout << "key : " << it.first << "," << "value : " << it.second << endl;
    }

    for(auto i: m){ // for manipulation/change 
        cout << "key ka double : " << i.first*2 << endl;
    }

    return 0;

}