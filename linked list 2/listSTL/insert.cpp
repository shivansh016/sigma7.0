#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> ll = {1,2,6};

    //insert a single element

    auto it = ll.begin();
    advance(it, 2); // moves the iterator to 3rd position
    ll.insert(it, 30); // insert 30 at iterator_position i.e. "it" position
    for(int x : ll){
        cout << x << "->"; 
    }
    cout <<"NULL\n" << endl; // 1->2->30->6->NULL

    //insert multiple copies
    
    ll.insert(it, 8, 40);
    for(int x : ll){
        cout << x << "->"; 
    }
    cout <<"NULL\n" << endl;

    //insert a range of elements

    list<int> ll1 = {1,2,7};
    list<int> ll2 = {4,5,6};

    auto itr =ll1.begin();
    advance(itr, 2);
    ll1.insert(itr, ll2.begin(), ll2.end());//ins
    for (int x : ll1){
        cout << x << "->";

    }
    cout << "NULL\n";

    return 0;
}