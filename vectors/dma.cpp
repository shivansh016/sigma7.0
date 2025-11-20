// showcasing the uses of new to dynamically allocate memory for an array and integer

#include<iostream>
using namespace std;

void funcInt(){
    int *ptr = new int ;
    *ptr = 5;
    cout << *ptr << endl;
    delete ptr;
}

void func( ){

    cout << "enter size: "<< endl;
    int size;
    cin>> size;
    int *ptr = new int[size]; 

    // to print values of ptr 
    int x=1;
    for (int i=0; i<size; i++){
        cout << x++ << " ";

    }
    cout << endl;
    delete[] ptr;// deletes the dynamically created memeory inside heap
}

int main (){
    func();
    cout << " array wala function ka kaam ends here " << endl;
    funcInt ();
    return 0;
}
