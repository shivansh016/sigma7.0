#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>

using namespace std;

int countUnordered(vector<int>& arr);
int countOrdered(vector<int> & arr);


int main(){
    vector<int> arr = {4,3,2,5,6,7,3,4,2,1};

    cout << "unique elemnts are : " << countUnordered(arr) << endl;
    cout << "\nUsing the set i.e. (ordered data it will give ) : \n" << endl;
    cout << "unique element are : " << countOrdered(arr) << endl;

    return 0;
}

int countOrdered(vector<int> & arr){
    
    set<int> s;
    for(int i=0; i<arr.size(); i++){
        s.insert(arr[i]);
    }


    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
    
    return s.size();
}

int countUnordered(vector<int> & arr){
    unordered_set<int> s;
    for(int i=0; i<arr.size(); i++){
        s.insert(arr[i]);
    }


    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
   
    return s.size();
}

// output :

// 1 7 6 4 3 2 5 
// unique elemnts are : 7

// Using the set i.e. (ordered data it will give ) :

// 1 2 3 4 5 6 7
// unique element are : 7