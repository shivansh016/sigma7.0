#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;

    for (int i=0; i<5; i++){
        vec.push_back(i);
    }

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}

// size tells the exact number of elements in the vector 
//while the capacity is total number of elements vector can store..
// Growth- size()- increases by 1 every time we add an element while capacity () doubles when we add an element (1,2,4,8... so on)