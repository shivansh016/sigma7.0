#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(5);

    cout<< "size :" << s.size() << endl;

    s.insert(2);
    s.insert(1);
    s.insert(1);

    cout << "size : " << s.size() << endl;

    if(s.find(3) != s.end()){
        cout << "3 exists\n" ;
    }else{
        cout << "3 doesn't exist\n";
    }

    if(s.find(10) != s.end()){
        cout << "10 exists\n" ;
    }else{
        cout << "10 doesn't exist\n";
    }

    s.erase(3);

    if(s.find(3) != s.end()){
        cout << "3 exists\n" ;
    }else{
        cout << "3 doesn't exist\n";
    }

    // printing elements
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;

    return 0;
    

}

