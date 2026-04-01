#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, int> m;

    // map<string,int, greater<string>> m; // will store in descending order of keys..

    m.insert({"India", 150});
    m["China"] = 150;
    m["US"] = 50;
    m["Russia"] = 15;
    m["Nepal"] = 10;

    // change the value of nepal key to 12
    m["Nepal"] = 12;

    cout << "India pop : " << m["India"] << endl;

    for(pair<string, int> x : m){ // will give the sorted order based on keys sorting in ascending order.. for descending use ==> map<string, greater<int>> m
        cout << x.first << ", " << x.second << endl;
    }

    if(m.count("Nepal")){
        cout << "Nepal exists" << endl;
    }

    if(m.count("CAnada")){
        cout << "CAnada exists" << endl;
    }else{
        cout << "CAnada doesn't exist" << endl;
    }

    return 0;
}