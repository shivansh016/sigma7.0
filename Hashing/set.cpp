#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    cout << "size :" << s.size() << endl; // 4 shows that repeated elements are not allowed

    s.erase(3);
    cout << "3 is now erased \n";
    
    if(s.find(3) != s.end()){
        cout << "3 exists\n";
    }else{
        cout << "3 doesn't exists\n";
    }

    s.insert(3);
    cout << "3 is added again\n";

    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}